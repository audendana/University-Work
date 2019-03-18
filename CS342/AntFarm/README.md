# CS342 Design Patterns
## Fall 2018
### PROJECT 2 README FILE
## Description


For our second assignment we are going to build an Ant Farm where several colonies of ants battle it out to be the last AntHill standing.

You are going to build an antfarm, and you're going to use some common design patterns to do it. The program will create several anthills in a meadow using the builder pattern. Each anthill will act as a factory that builds different kinds of Ants. What kinds of ants are built each turn will depend on the Anthill factories. Ants must leave the anthill and randomly wander the meadow in search of food.  When they do, they may randomly run into other ants. If the other ant is from another hill and is of a certain type, they should fight. The program will run cycles in which the state of the meadow will print to the console each cycle. The program will continue until only a single anthill is left.

### Meadow
* The meadow will be a 20 x 20 grid
* Each grid element should contain a Cell object that is initialized with the following information
    * hill = None
    * food = 0
    * ants = []
* The Meadow class is responsible for initializing the meadow and managing each cycle.
    * `__init__`:
        * Creates builder objects that configure and place Anthills in the meadow at various starting positions.
    * `cycle`:
        * Each cycle, the following should occur:
            * Food: The meadow should ensure 'food' is randomly placed in a couple locations each cycle
                * In practice, this means randomly selecting a few cells every cycle and incrementing the amount of food in those cells
            * The meadow should make sure each anthill has an opportunity to direct all of its ants and build any additional ants
            * At the end of every cycle present the user with a menu that asks:
                * If they would like to display the state of the meadow
                * Run the next n cycles without halting
* A meadow spawns between 3-4 anthills on initialization
    * Anthills are spawned by ‘releasing a queen’ (builder object) who randomly selects a grid cell to build her anthill, then creates and initializes the anthill.
    * Anthills start with 1 piece of food and any additional attributes you think it needs (1 worker, 1 warrior, etc.)

### Anthill
An anthill takes up a single grid Cell and contain references to all its ants.
* Anthills can spawn ants of the following type on each cycle
    * foragers (used to search for food)
    * warriors (used to kill other ants)
    * workers (used to create rooms in the anthill)
* There are two limitations on the number of ants:
    * You cannot spawn more ants unless you have enough rooms (more information on rooms below).
        * 1 room allows you to create 1 ant per turn
    * You cannot create more ants than the number of cell rows
        * If your grid is 20x20, each hill cannot have more than 20 ants

### Ants
When an ant is created, it will immediately start working according to its type.
* For ants that wander the meadow, each ant moves 1 square in the meadow per turn.
     * Movement should be random, but the ant should not move off the grid. For example, if the ant is in a corner cell, it should only have 2 directions it can travel in and not be able to leave the ‘meadow’.

There are 3 ant types:
* `Forager`
    * The Forager searches each square for food as it wanders the meadow
        * Food can only be found by foragers
        * Once food is found, the forager must make its way back to the AntHill. If it dies on it's way back, the food is lost.
* `Warrior`
    * The warrior searches each cell for other ants as it wanders the meadow
        * If the other ant is a forager and from a different anthill, the forager has a 50% chance of dying.
        * If the other ant is a warrior and from a different anthill, a winner is selected based on a random algorithm of your choosing
    * For every fight the warrior wins, it gains a some attribute. This should be implemented as a decorator pattern.
        * For example, you may have 3 additional classes (SpeedBoost, SecondChance, and OddsBoost), and each time a Warrior wins a fight, you wrap the warrior in a new booster object. The booster object should be indistinguishable from the warrior class, only adding to it.
* `Worker`
    * The worker ant will create rooms that will in turn spawn your ants.

### Rooms

Ants are spawned by rooms. Each room spawns 1 ant of a specified type per cycle as long as certain requirements are met.

* A room can only spawn ants of a certain type (forager, worker, warrior). This must be decided when a room is created by the worker.
    * For example, you will have a `WorkerRoom`, `ForagerRoom`, and `WarriorRoom` that each create ants of that type only.
* Creating rooms costs 1 food and kills the worker ant
* Rooms are only effective if they have a worker, so if your hill only has 4 workers, then only 4 rooms will spawn new Ants, even if you have 10 rooms.

## Part B - Displaying and Ending the Simulation

An Anthill can be destroyed in several different ways:

* If a warrior of an ant colony wanders onto the anthill of another ant colony, it has a low chance to destroy the entire anthill (something like 1/5, but experiment with what you think works best).
    * If it succeeds in killing the hill of another colony, the colony (including all its ants) dies and is deleted from the meadow.
    * Otherwise, the warrior is killed
* If an anthill has 0 foragers at the end of a turn, it is destroyed

The simulation ends when there is 1 (or less) active colonies.


## Part C - Technical Requirements: (Design patterns bolded)
* There is single base Ant class and three subclasses, Forager, Warrior, and Worker.
* Each Room is an AntFactory that contains a factory method to create the specific ant type. Once the ant is created, it should give them a unique ID and send them to work.
* On initialization, a Queen object should be created (__builder__), then should select a random location in the meadow for their ant hill.
    * The queen should configure the anthill first with initial number of rooms, food, and ants, then place it in the meadow.
* Warriors should have multiple __decorator__ classes that wrap the warrior in additional functionality
