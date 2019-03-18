# CS342 Design Patterns
## Fall 2018
### PROJECT 1 README FILE
## Description

For our first assignment we are going to simulate the universe, and then search it for intelligent life. There will be two parts to this project. In Part A you will build a universe of stars and planets. Each star will have a type, an x, y, and z coordinate, and a random range of planets orbiting the star.


## Part 1

### Part A - The Stars

You should first create a Universe class as a container class for all your stars, with a method to generate your universe. The stars should derive from a base star class, and fall into one of 3 categories. Each Star type will have attributes that will affect its likelihood of intelligent life:

* DwarfStar
   * Chances of life: 0.0006
   * Range of planets: 8-15
   * Goldilocks Zone: 30-90
   * Recharge: 2**20
* GiantStar
   * Chances of life: 0.0005
   * Range of planets: 5-10
   * Goldilocks Zone: 100-250
   * Recharge: 2**30
* MediumStar
   * Chances of life: 0.0009
   * Range of planets: 2-9
   * Goldilocks Zone: 60-140
   * Recharge: 2**25

:bulb: The values above should be hard-coded into your program and adjusted
to suit your design if necessary.

Each star will have an x,y,z coordinate to give it a location in space. No two stars should have the same x, y, z coordinates. You will need to use these coordinates to navigate from star to star, so the coordinates must be readable but should not be writable, using python private variable conventions. You should randomly generate these x,y,z coordinates, each in the range of (2^3..2^64)-1.  

Each star should also have a recharge amount to be used by the probe to refuel. A larger star should have a higher recharge amount. For example, I use 2^20, 2^25, 2^30 for the Dwarf, Medium, and Giant Stars respectively. You can adjust these numbers to suit your program, but it must be *possible* to run out of fuel.

Lastly, each star will randomly generate a list of planets (more information on planets below). It should have num planets, where num is in the range of planets given above (inclusive). When you generate the planets, you will need to also randomly assign the planet’s distance from the star in millions of miles. Multiple planets can have the same distance from a star.

### Part B - Planets


Each star will have multiple planets, each with 3 different types:

* RockyPlanet
* GaseousPlanet
* HabitablePlanet

You should randomly assign planet types as they are created, and each Planet should derive from a base Planet class. The Planet base class should contain the planet’s distance from the star in millions of miles.

For example, One star, which is a Giant, may have 6 planets, 2 Rocky, 3 Gaseous, and 1 Habitable. Another Giant Star might have 8 planets, all of which are Gaseous.

Each planet should also have a unique id, preceded by a letter identifying what kind of planet it is, ‘r’ for Rocky, ‘g’ for Gaseous, and ‘h’ for Habitable.


### Part C - Life

We will be using the Star’s chances of life instance variable to mark if a planet has intelligent life. Even if the planet is marked as possible for intelligent life, it then must be within the so-called goldilocks zone for its star and must be a HabitablePlanet type.

If all of these conditions are met, you should mark the planet as having intelligent life. Otherwise, mark it as without life.

Once you have your universe set up, you should add a method to your Universe class that prints the number of stars of each type and how many planets of each type correspond to each star. (See below for sample output)

## Part 2 - The Search

### Part A - Searching for Life
Once you have generated your universe with stars, planets, and (possibly) life, it’s time to search for life. To do so you will need a ‘probe’ object that will search star to star, using an algorithm of your choosing to select which star to go to next. In this README you must explain your search algorithm, and defend why you chose it.


As you visit each star you will use fuel. Your probe will have an initial fuel amount, and can recharge at each star. The recharge amount depends on the type of star you are visiting. After recharging, your probe will check the Star’s planets, and should mark that star as visited so you don’t revisit already explored stars.  Your search ends when your probe finds a planet with intelligent life. In order for your probe to deliver the information, it must have enough fuel to return to its starting point, which means you have to keep track of the probe’s starting coordinates.

You will need to keep track of some data as you explore your simulated universe.

* The probe's starting coordinates
* How many Stars you have visited
* How many Planets you have explored
* The total distance you have traveled before finding intelligent life
   * You can use the [3 dimensional distance formula](https://www.varsitytutors.com/hotmath/hotmath_help/topics/distance-formula-in-3d) to determine the distance between stars.  

When you finally find life and successfully return to the origin, the probe should print the above information and the unique ID of the planet that contained life.

If no life was found or the probe runs out of fuel, print the above information and a message noting this.


## Sample Output:

This was run with 2**10 stars:

```
Total number of stars in my universe: 1025
There are 380 Giant Stars with:
        1056 Gaseous Planets
        1092 Rocky Planets
        1082 Habitable Planets
        0 Planets with Intelligent Life

There are 303 Dwarf Stars with:
        1275 Gaseous Planets
        1219 Rocky Planets
        1277 Habitable Planets
        0 Planets with Intelligent Life

There are 342 Medium Stars with:
        715 Gaseous Planets
        747 Rocky Planets
        807 Habitable Planets
        1 Planets with Intelligent Life

==========

Your origin was (4576, 76584476, 46508759)
Traveled 1.6731455226093466e+20 miles
        You have 5.870783888950368e+3 fuel remaining
        Visited 131 stars
        Explored 1223 planets
Found life on planet h8657
```

### Implementation
We have 3 star types Dwarf, Medium and Giant.
Each star type has a list of randomly generatedPlanets as an attribute

The universe holds all the stars in a dictionary of dictionaries with
  1 -> dictionary of all dwarf stars
  2 -> dictionary of all medium Stars
  3 -> dictionary of all giant Stars

  At first the probe class took this dictionary without remaking it and I
  tried to calculate all the distances from it which took to long and was overly
  tedious

  So now the probe class takes the dictionary and remakes it into a single
  dictionary using the probe.createStarMapFull() method
  This gives a new dictionary of the starID's mapped with their respective object

  Then we create a start point for the probe at a random star using the
  probe.starPoint() method

  We keep track of all the visited and unvisited stars within the probe class.

  The probe.path() method is what allows us to explore
  First we get the closest star to us by checking all the distances in the unvisited
  star list.  Then we check if we can visit the star and return to the start coord.
  If we can visit the star we visit it and remove the star from the unvisited list and
  add it to the visited list.

  We loop through this until we either visit all the stars, run out of fuel and cant check more,
  or we find life.

  The probe class will visit all stars or find life with self._FUEL = 2**45 but wont run out of fuel
  With self._FUEL = 2**40 it will either run out of fuel or find life
