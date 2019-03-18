import random
from Planet import *
class Star:
    def __init__(self):
        self._x = 0
        self._y = 0
        self._z = 0
        self._coordinates = self.generateCoordinates()

    def generateCoordinates(self):
        self._x = random.randrange(2**3, 2**35)
        self._y = random.randrange(2**3, 2**35)
        self._z = random.randrange(2**3, 2**35)

        return [self._x, self._y, self._z]

    def getCoordinates(self):
        return self._coordinates


class DwarfStar(Star):
    def __init__(self, starID):
        super().__init__()
        self._col = 0.0006
        self._numOfPlanets = list(range(8,16))
        self._goldilocks = list(range(30,90))
        self._recharge = 2**20
        self._planets = []
        self._starID = "D" + str(starID)

    def addPlanets(self):
        numOfPlanets = random.choice(self._numOfPlanets)
        for i in range(numOfPlanets):
            planet = Planet('DwarfStar').generatePlanet()
            self._planets.append(planet)

    def getGoldiLocksRange(self):
        return self._goldilocks

    def getCOL(self):
        return self._col

    def getPlanets(self):
        return self._planets

    def getStarID(self):
        return self._starID

    def getRecharge(self):
        return self._recharge

    def getRecharge(self):
        return self._recharge


class GiantStar(Star):
    def __init__(self,starID):
        super().__init__()
        self._col = 0.0005
        self._numOfPlanets = list(range(5,10))
        self._goldilocks = list(range(100,250))
        self._recharge = 2**30
        self._planets = []
        self._starID = "GA" + str(starID)

    def addPlanets(self):
        numOfPlanets = random.choice(self._numOfPlanets)
        for i in range(numOfPlanets):
            planet = Planet('GiantStar').generatePlanet()
            self._planets.append(planet)

    def getGoldiLocksRange(self):
        return self._goldilocks

    def getCOL(self):
        return self._col


    def getPlanets(self):
        return self._planets

    def getStarID(self):
        return self._starID

    def getRecharge(self):
        return self._recharge

class MediumStar(Star):
    def __init__(self, starID):
        super().__init__()
        self._col = 0.0009
        self._numOfPlanets = list(range(2,9))
        self._goldilocks = list(range(60,140))
        self._recharge = 2**25
        self._planets = []
        self._starID = "M" + str(starID)

    def addPlanets(self):
        numOfPlanets = random.choice(self._numOfPlanets)
        for i in range(numOfPlanets):
            planet = Planet('MediumStar').generatePlanet()
            self._planets.append(planet)

    def getGoldiLocksRange(self):
        return self._goldilocks

    def getCOL(self):
        return self._col

    def getPlanets(self):
        return self._planets

    def getStarID(self):
        return self._starID

    def getRecharge(self):
        return self._recharge
