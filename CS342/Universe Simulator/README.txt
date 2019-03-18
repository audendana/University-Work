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
