# A*-Algorithm
AI Assignments
main.cpp file is the code for Romanian Graph
Romanian Graph is describes the following problem

Problem: On holiday in Romania; currently in Arad. Flight leaves tomorrow from Bucharest. Find a short route to drive to Bucharest.

Formulate problem:
states: various cities
actions: drive between cities
solution: sequence of cities, e.g., Arad, Sibiu, Fagaras, Bucharest.

~ Deterministic, fully observable =⇒ single-state problem Agent knows exactly which state it will be in; solution is a sequence. 
~ Non-observable =⇒ conformant problem 
      Agent may have no idea where it is; solution (if any) is a sequence.
~ Nondeterministic and/or partially observable =⇒ contingency problem
      - percepts provide new information about current state.
      - solution is a tree or policy 
      - often interleave search, execution
~ Unknown state space =⇒ exploration problem (“online”)

![WhatsApp Image 2021-12-28 at 11 34 38 PM](https://user-images.githubusercontent.com/61793052/147594786-d1fa9723-64f9-4fce-975f-f425c44bba91.jpeg)


main.py file is the code for The 8-puzzle problem

~ It can be generalized to 15-puzzle, 24-puzzle, or (n2 − 1)-puzzle for n ≥ 6.
~ Reduce the original problem to a search problem.
~ A solution for the search problem is a path initial state–goal state.
~ The solution for the original problem is either
      - the sequence of actions associated with the path or
      - the description of the goal state.
     
     States: configurations of tiles
     Operators: move one tile Up/Down/Left/Right

~ There are 9! = 362, 880 possible states (all permutations of {⊓⊔, 1, 2, 3, 4, 5, 6, 7, 8}).
~ There are 16! possible states for 15-puzzle.
~ Not all states are directly reachable from a given state. (In fact, exactly half of them are reachable from a given state.)

![WhatsApp Image 2021-12-28 at 11 12 59 PM](https://user-images.githubusercontent.com/61793052/147594826-67cda9e8-0092-45bc-984f-67e5ef361ef6.jpeg)

