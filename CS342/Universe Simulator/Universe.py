import random
from Star import *
from Planet import *
from Probe import *

class Universe:
    def __init__(self, numOfDwarf, numOfMed, numOfGiant):

        self._stars = {}
        self._coordinates = {}
        self._numOfDwarf = numOfDwarf
        self._numOfMed = numOfMed
        self._numOfGiant = numOfGiant

    def generateUniverse(self):
        self._tempMap = {}
        self._coordTemp = {}

        count = 1

        #Make Dwarf Stars
        for i in range(self._numOfDwarf):
            dwarfStar = DwarfStar(count)
            count +=1
            dwarfStar.addPlanets()

            coordExist = False
            while(coordExist == False):
                dwarfStar.generateCoordinates()
                dwarfCoord = dwarfStar.getCoordinates()
                if(dwarfCoord in self._coordTemp.values()):
                    coordExist = False
                else:
                    self._coordTemp[i] = dwarfCoord
                    coordExist = True

            self._tempMap[i] = dwarfStar
        self._stars[1] = self._tempMap
        self._coordinates[1] = self._coordTemp

        count = 1

        # Make Medium Stars
        self._tempMap2 = {}
        self._coordTemp2 = {}
        for i in range(self._numOfMed):
            medStar = MediumStar(count)
            count +=1
            medStar.addPlanets()

            coordExist = False
            while(coordExist == False):
                medStar.generateCoordinates()
                medCoord = medStar.getCoordinates()
                if(medStar in self._coordTemp2.values() or medStar in self._coordTemp.values()):
                    coordExist = False
                else:
                    self._coordTemp2[i] = medCoord
                    coordExist = True
            self._tempMap2[i] = medStar

        self._stars[2] = self._tempMap2
        self._coordinates[2] = self._coordTemp2


        # Make Giant Stars
        count = 1
        self._tempMap3 = {}
        self._coordTemp3 = {}
        for i in range(self._numOfGiant):
            giantStar = GiantStar(count)
            count +=1
            giantStar.addPlanets()

            coordExist = False
            while(coordExist == False):
                giantStar.generateCoordinates()
                giantCoord = giantStar.getCoordinates()
                if(giantCoord in self._coordTemp3.values() or giantCoord in self._coordTemp2.values()
                or giantCoord in self._coordTemp.values()):
                    coordExist = False
                else:
                    self._coordTemp3[i] = giantCoord
                    coordExist = True

            self._tempMap3[i] = giantStar
        self._stars[3] = self._tempMap3
        self._coordinates[3] = self._coordTemp3

    def getStars(self):
        return self._stars

    def printData(self):
        totalNumOfStars = len(self._stars[1]) + len(self._stars[2]) + len(self._stars[3])
        totalNumOfDwarf = len(self._stars[1])
        dwarfGasPlanets = 0
        dwarfRockyPlanets = 0
        dwarfHabitPlanets = 0
        dwarfLife = 0

        totalNumOfMed = len(self._stars[2])
        medGasPlanets = 0
        medRockyPlanets = 0
        medHabitPlanets = 0
        medLife = 0

        totalNumOfGiant = len(self._stars[3])
        giantGasPlanets = 0
        giantRockyPlanets = 0
        giantHabitPlanets = 0
        giantLife = 0


        for i in range(totalNumOfDwarf):
            star = self._stars[1][i]
            planet = star.getPlanets()

            for j in range(len(planet)):
                if(type(planet[j]) is GaseousPlanet):
                    dwarfGasPlanets +=1
                elif(type(planet[j]) is RockyPlanet):
                    dwarfRockyPlanets +=1
                else:
                    dwarfHabitPlanets +=1
                    if(planet[j].getLife() == True):
                        dwarfLife+=1


        for i in range(totalNumOfMed):
            star = self._stars[2][i]
            planet = star.getPlanets()
            for j in range(len(planet)):
                if(type(planet[j]) is GaseousPlanet):
                    medGasPlanets += 1
                elif(type(planet[j]) is RockyPlanet):
                    medRockyPlanets +=1
                else :
                    medHabitPlanets +=1
                    if(planet[j].getLife() == True):
                        medLife +=1


        for i in range(totalNumOfGiant):
            star = self._stars[3][i]
            planet = star.getPlanets()
            for j in range(len(planet)):
                if(type(planet[j]) is GaseousPlanet):
                    giantGasPlanets +=1
                elif(type(planet[j]) is RockyPlanet):
                    giantRockyPlanets +=1
                else:
                    giantHabitPlanets += 1
                    if(planet[j].getLife() == True):
                        giantLife +=1

    #    print("Total number of stars in my universe: " , totalNumOfStars)
        print("There are a total of", totalNumOfStars, "stars in this universe")
        print("There are ", totalNumOfDwarf, "Dwarf Stars with: ")
        print( dwarfGasPlanets, " Gaseous Planets")
        print( dwarfRockyPlanets, " Rocky Planets")
        print( dwarfHabitPlanets, " Habit Planets")
        print(dwarfLife, " Planets with intelligent life")

        print()
        print()
        print("There are ", totalNumOfMed, "Medium Stars with: ")
        print( medGasPlanets, " Gaseous Planets")
        print( medRockyPlanets, " Rocky Planets")
        print( medHabitPlanets, " Habit Planets")
        print(medLife, " Planets with intelligent life")

        print()
        print()
        print("There are ", totalNumOfGiant, "Giant Stars with: ")
        print( giantGasPlanets, " Gaseous Planets")
        print( giantRockyPlanets, " Rocky Planets")
        print( giantHabitPlanets, " Habit Planets")
        print(giantLife, " Planets with intelligent life")
