Fantasy game: King rescues princess from a dragon. 

Storyline:

King recives info from a messenger, talks to his advisor, gathers his tools(using a key), rides on his horse(using a key) and starts from castle 
King goes to the forest, talks to a forest native(answer riddle), find/decipher map to the cave, who takes him to an animal spot. Fights an animal to get a powerful sword.( Gets additional armor from the animal). Finds/eat/pick fruit used to heal
King goes to the dragon cave, fights the dragon and rescues the princess. END

Requirements: 

1. Multiple environments: Castle, Forest, Dragon cave.
2. Multiple charachters: This will be fulfilled by messenger, advisor, forest native, dragon(maybe?), princess(maybe?)
3. Multiple actions: Movement: run(1 sec), walk(2 secs)
                     Environment: look, touch, examine, dig, climb
                     Interaction: Objects -> picks up, put down, throw
                                  Other characters -> speak(forest native), attack(animal, dragon), persuade(advisors, princess)
4. Multiple usable items: Key used by king, horse used by king to go to forest/cave, fruit, special fruit.
5. Basic Plot: End Goal -> Rescue Princess
               Multiple Puzzles ->  Key for tools, Answer riddle, Get Special fruit, Defeat Lion, Defeat Dragon.
               Lose Game -> King doesn't decide,Cannot solve riddle, defeat from lion, defeat from dragon. 
6. HELP: list all possible actions. 
7. Error checking: Validate all user inputs. 


Descriptive Design: 
Grid might have something(object/person). When king will walk to that grid, he can interact with grid person, or pick up/down/throw objects. He can look/touch/examine the object on that grid. 
Once object is picked up, king has that object in his possession. 
King will move to different grids. 
There might be grids that are empty. 
After each movement, print the grid. Additionally, user can enter print to print current grid

Environment 1: 
9 Grids

King is at start. 
Grid 1: King receives info from a messenger. 
Grid 2: He talks to his advisor. Either continue(save princess) or quit(do not save princess)
Grid 3: He collects his tools(sword/armor).
Grid 4: Rides on his horse.
Grid 5: Departs castle. ->> Enters Forest
4 empty grids here. 

Environment 2: 
Ties horse to a tree. 
King goes to the Forest Native Leader
Leader asks him a riddle, King solves it. If he doesn't solve it, game ends. 
Leader gives him map to the dragon cave
King also finds a special fruit that helps to heal. If not found, king will die from dragon fight as he wont have enough strength. 
King goes to Lion secret spot(grid).
Lion is wearing armor but not a helmet(hint to hit head).
King fights Lion, gets a special sword and armor from Lion. Reduce King's health.
King leaves forest on his horse. 
Read map to enter cave.
Display message- Your health is low, do you want to continue or explore forest(hint) 
->> Enters Dragon Cave

Environment 3: 
King finds the cave. 
King eats fruit and heals himself. Or eats poison and dies.
Ties horse to a tree.
Fights dragon.
Rescues Princess. 


* User enters help. Print the environment with quick description about grids and their content. 
* Movements: move, run 
* Environment: Look at any object, it will print the name of that object
               Touch any object in front of you. It will print "Touched <objectName>"
               Examine objects in front of you. It will print name and description of the object. 

* Interaction: Objects can be picked, put down, thrown. King can pick up/down infinite times but if object is thrown, it will disappear(delete from grid) and cannot be picked again. 
              King will persuade advisor, talk to forest leader, attack lion, attack dragon.

Notes: Randomize the grids(if possible)

Assumptions: 
User cannot go back to an environment. If king moves backward at step 1(of an environment), no action. 
King has to finish everything to go to the next environment.
