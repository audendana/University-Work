import random
import math
from Star import *

class Probe:
    def __init__(self, starMap):
        self._startCoord = []
        self._habitPlanetID = ""
        self._totalDistTraveled = 0
        self._FUEL = 2**45
        self._starMap = starMap
        self._visited = []
        self._unvisited = []
        self._currentCoord = []
        self._starDistances = {}
        self._currentStar = None
        self._firstTrip = True
        self._planetCount = 0
        self._starMapFull = self.createStarMapFull()
        self._noLife = False


    def startPoint(self):
        star =  random.choice(list(self._starMapFull.values()))

        self._currentStar = star
        self._startCoord = star.getCoordinates()
        self._currentCoord = self._startCoord
        self._visited.append(star)

        for key in self._starMapFull:
            self._unvisited.append(self._starMapFull[key])


        self.removeFromUnvisited(star)




    def path(self):
        while(self._noLife == False):
            closestStar = self.nextStar()
            if(closestStar.getStarID() == "DOUT"):
                print("Searched through all stars")
                print()
                return False

            else:
                if(self.checkIfWeCanGo(closestStar)):
                    self.visitStar(closestStar)
                    if(self.checkForLife(closestStar)):
                        self._noLife = True
                        return True
                else:
                    print("Not enough fuel left to go to any more stars")
                    print()
                    return False



    def nextStar(self):
        self._starDistances.clear()
        self.calculateAllDistances()
        nextStar = self.getClosestStar()
        return nextStar

    def visitStar(self, starObj):
        self._visited.append(starObj)
        self.removeFromUnvisited(starObj)
        self._FUEL = self._FUEL - self._starDistances[starObj] + starObj.getRecharge()
        self._currentStar = starObj
        self._currentCoord = starObj.getCoordinates()
        self._totalDistTraveled += self._starDistances[starObj]


    def checkForLife(self,starObj):
        planets = starObj.getPlanets()
        for planet in planets:
            if(planet.getPlanetType() == "Habit"):
                self._planetCount +=1
                if(planet.getLife()):
                    self._habitPlanetID = planet.getPlanetID()
                    return True
            else:
                self._planetCount+=1
        return False

    def checkIfWeCanGo(self, starObj):
        if self._firstTrip == True:
            self._firstTrip == False
            distanceToStar = self._starDistances[starObj]
            distThereBack = distanceToStar*2
            finalGas = self._FUEL - distThereBack + starObj.getRecharge()
            if(finalGas > 2**15):
                return True
            else:
                return False
        else:
            distToStart = self.calcDistBackToStart()
            distThereBack = distToStart + self._starDistances[starObj]
            finalGas = self._FUEL - distThereBack + starObj.getRecharge()
            if(finalGas > 2**15):
                return True
            else:
                return False

    def getClosestStar(self):
        shortestStar = min(self._starDistances, default = 0, key=self._starDistances.get)
        if(shortestStar == 0):
            starObj = DwarfStar("OUT")
            return starObj
        else:
            return shortestStar

    def calculateAllDistances(self):
        for star in self._unvisited:
            self._starDistances[star] = self.calcDistanceBetweenStars(star)


    def calcDistanceBetweenStars(self, starObj):
        x = self._currentCoord[0]
        y = self._currentCoord[1]
        z = self._currentCoord[2]

        x1 = starObj.getCoordinates()[0]
        y1 = starObj.getCoordinates()[1]
        z1 = starObj.getCoordinates()[2]

        first = (x-x1)**2
        second = (y-y1)**2
        third = (z-z1)**2

        total = first+second+third
        retVal = math.sqrt(total)
        return retVal

    def calcDistBackToStart(self):
        x = self._currentCoord[0]
        y = self._currentCoord[1]
        z = self._currentCoord[2]

        x1 = self._startCoord[0]
        y1 = self._startCoord[1]
        z1 = self._starCoord[2]

        first = (x-x1)**2
        second = (y-y1)**2
        third = (z-z1)**2

        total = first+second+third
        retVal = math.sqrt(total)
        return retVal

    def removeFromUnvisited(self, starObj):
        self._unvisited.remove(starObj)


    def checkIfContained(self, starObj, checkList):
        if(starObj in checkList):
            return True
        else:
            return False




    # Creates a dict of all the stars instead of having a dict within a dict
    def createStarMapFull(self):
        retVal = {}
        dwarfStars = self._starMap[1]
        for i in range(len(self._starMap[1])):
            starID = dwarfStars[i].getStarID()
            retVal[starID] = dwarfStars[i]


        medStars = self._starMap[2]
        for i in range(len(self._starMap[2])):
            starID = medStars[i].getStarID()
            retVal[starID] = medStars[i]


        giantStars = self._starMap[3]
        for i in range(len(self._starMap[3])):
            starID = giantStars[i].getStarID()
            retVal[starID] = giantStars[i]

        return retVal


    def printData(self):
        if(self._noLife == False):
            print("Your origin was, ", self._startCoord)
            print("Traveled ", self._totalDistTraveled, "miles")
            print("You have ", self._FUEL, "remaining")
            print("Visited ", len(self._visited), "stars")
            print("Explored ", self._planetCount, "planets")
            print("No life was found")
        else:
            print("Your origin was, ", self._startCoord)
            print("Traveled ", self._totalDistTraveled, "miles")
            print("You have ", self._FUEL, "remaining")
            print("Visited ", len(self._visited), "stars")
            print("Explored ", self._planetCount, "planets")
            print("Found life on planet", self._habitPlanetID)
