#!/usr/bin/env python3

import angr
import claripy

# Make a symbolic string. We'll need this later. Let's assume it's no longer than 40 characters
flag = claripy.BVS('flag', 8*40)

# Make a new project for our binary
proj = angr.Project('./basic_crackme')

MAIN = proj.loader.find_symbol('main')
WIN = proj.loader.find_symbol('win')
LOSE = proj.loader.find_symbol('lose')

# Create a new state at the entrypoint (_start) and pass in our symbolic stdin string
st = proj.factory.entry_state(args=['./basic_crackme', flag])
# A SimulationManager manages collections (stashes) of states
simgr = proj.factory.simgr(st)

# Symbolically execute until we reach main()
simgr.explore(find=MAIN.rebased_addr)
# Move all the other states that aren't main() to the 'inactive' stash
simgr.move('active', 'inactive')
# The state that found our explore(find=) condition gets put into the 'found' stash, so move it back
simgr.move('found', 'active')

# Find a path to win() and prune states that reach lose()
simgr.explore(find=WIN.rebased_addr, avoid=LOSE.rebased_addr)

# If we get here, then we've found a state that reaches win()
# Print out what stdin must be to get to the found state
found_state = simgr.found[0]
concrete_flag = found_state.solver.eval(flag, cast_to=bytes).rstrip(b'\0')
print(f'Flag is: {concrete_flag.decode("utf-8")}')
