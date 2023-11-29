Basic blocks for the program

Object Base Class: name, description, symbol, print
Special Fruit -> Heals king, increases his health
Tree -> Used to tie horse
Sword -> used to attack the lion
Special Sword -> used to attack the dragon
Armor -> 
Special Armor
Key
Map

Player Interface: King
NPC: Advisor, Messenger, Princess, Forest Leader, Dragon, Lion, Horse


Grid Base Class: boolean empty, player, object, NPC
Empty Grid -> empty: true, player: null, object: null
Grid with person -> empty: false, person: Person, object: null
Grid with object -> empty: false, person: null, object: Object



Environment Base Class: Array of Grids
Castle 
Forest
Dragon Cave

Basic Implementation Phase 1:
Player can 
1. Move between 2 adjacent locations
2. Interact with the environment in one way( eg examine a room)
3. Interact with an object in 2 ways (eg pick up and put down)
4. Unit test for movement and interacting with objects actions

Unit Testing for all of the code


Duties:
Walker: Player interface, King Class, King Unit Tests
Parsa: Environment interface, Castle Class, Grid Base Class, Castle Unit Tests, Grid Unit Tests
Harmanjit: NPC interface, Object interface, Messenger, Advisor, Main Game running, Messenger Unit Tests, Advisor Unit Tests, Main game unit tests

Time line:
Walker -> Player Interface 
Harmanjit -> NPC interface, Object interface
Parsa -> Grid Base Class, Environment interface, Castle class
Walker -> King Class
Harmanjit -> Messenger, Advisor, Main
