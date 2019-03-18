import random
from Star import *

class Planet:
    def __init__(self, starType):
        self._dist  = random.randrange(1,301)
        self._starType = starType

    def generatePlanet(self):
        planetType = random.randrange(1,4)
        #1=Rocky, 2=Habit, 3=Gas
        if planetType == 1: #rocky
            planet = RockyPlanet(self._starType, self._dist).makeRockyPlanet()
            return planet
        elif planetType == 2: #HabitablePlanet
            planet = HabitablePlanet(self._starType, self._dist).makeHabitablePlanet()
            return planet
        else:
            planet = GaseousPlanet(self._starType, self._dist).makeGaseousPlanet()
            return planet





class RockyPlanet(Planet):
    def __init__(self, starType, dist):
        self._life = False
        self._ID = ""
        self._starType = starType
        self._dist = dist
        self._planetType = "Rocky"

    def makeRockyPlanet(self):
        idNum = random.randrange(1,150001)
        self._ID = 'r' + str(idNum)
        return self

    def getPlanetID(self):
        return self._ID

    def getPlanetType(self):
        return self._planetType

class HabitablePlanet(Planet):
    def __init__(self, starType, dist):
        self._life = False
        self._ID = ""
        self._starType = starType
        self._dist = dist
        self._planetType = "Habit"

    def makeHabitablePlanet(self):
        idNum = random.randrange(1,150001)
        self._ID = 'h' + str(idNum)


        # Checks to see what the star type is then checks
        # If the planet is in the habitable zone
        # Then calculates probability of life

        goldiLocksRangeDwarf = list(range(30,91))
        COLDwarf = 0.0006
        goldiLocksRangeGiant = list(range(100,251))
        COLGiant = 0.0005
        goldiLocksRangeMed = list(range(60,141))
        COLMed = 0.0006

        if(self._starType == 'DwarfStar'):
            if(self._dist in goldiLocksRangeDwarf):
                if(random.random() < COLDwarf):
                    self._life = True
        elif(self._starType == 'GiantStar'):
            if(self._dist in goldiLocksRangeGiant):
                if(random.random() < COLGiant):
                    self._life = True
        else:
            if(self._dist in goldiLocksRangeMed):
                if(random.random() < COLMed):
                    self._life = True
        return self

    def getLife(self):
        return self._life

    def getPlanetID(self):
        return self._ID

    def getPlanetType(self):
        return self._planetType

class GaseousPlanet(Planet):
    def __init__(self, starType, dist):
        self._life = False
        self._ID = ""
        self._starType = starType
        self._dist = dist
        self._planetType = "Gas"

    def makeGaseousPlanet(self):
        idNum = random.randrange(1,150001)
        self._ID = 'g' + str(idNum)
        return self

    def getPlanetID(self):
        return self._ID

    def getPlanetType(self):
        return self._planetType
