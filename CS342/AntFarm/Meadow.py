from Cell import *
from Queen import *
import random
class Meadow:
    def __init__(self):
        self._grid = []
        self._cycleNum = 0
        self._hills = []
        self._totalAntNum = 0
        self._holderX = 0
        self._holderY = 0
        self.antIDCount = 0
        self.makeGrid()
        self.makeBuilders()




    def makeBuilders(self):
        randNumOfHills = random.randrange(3,5)
        for i in range(randNumOfHills):
            queen = Queen(self._grid)
            antHill = queen.selectLocation().addInitRooms().addInitFood().addInitAnts(self.antIDCount).build()
            x = antHill.getXCoord()
            y = antHill.getYCoord()
            self._holderX = x
            self._holderY = y
            self._grid[y][x].setFood(1)
            self._grid[y][x].setHill(antHill)
            self._hills.append(antHill)
            self.antIDCount += 20

    def makeGrid(self):
        for i in range(20):
            row = [Cell(j,i) for j in range(20)]
            self._grid.append(row)

    def cycle(self):
        self._cycleNum +=1
        randNumOfCellsForAdditionalFood = random.randrange(3,5)

        for i in range(randNumOfCellsForAdditionalFood):
            x = random.randrange(0,10)
            y = random.randrange(0,10)

            if(self._grid[y][x].getHill() != None):
                self._grid[y][x].setFood(1)
                self._grid[y][x].getHill().addFood(1)
            else:
                (self._grid[y][x].setFood(1))
            print("Food added too: ", x, y)

        for hill in self._hills:
            #count+=1
            print()
            for ant in hill.getAnts():
                if(type(ant) is type(Forager(910))):
                    if(ant.haveFood() == False):
                        #Ant doesnt have food
                        prevX = ant.getCurrentCoord()[0]
                        prevY = ant.getCurrentCoord()[1]
                        ant.move()

                        x = ant.getCurrentCoord()[0]
                        y = ant.getCurrentCoord()[1]
                        self._grid[y][x].addAnts(ant)
                        self._grid[prevY][prevX].removeAnt(ant)

                        if(self.checkFood(x,y)):
                            ant.setFood(self._grid[y][x].getFood())
                            ant.setHaveFood(True)
                            foodRemove = (self._grid[y][x].getFood())*-1
                            self._grid[y][x].setFood(foodRemove)
                            print("Forager ant:", ant, "found food")
                    else:
                        prevX = ant.getCurrentCoord()[0]
                        prevY = ant.getCurrentCoord()[1]
                        self._grid[prevY][prevX].removeAnt(ant)
                        ant.returnToHill()
                        x = ant.getCurrentCoord()[0]
                        y = ant.getCurrentCoord()[1]
                        self._grid[y][x].addAnts(ant)

                        if(x == hill.getXCoord() and y == hill.getYCoord()):
                            antFood = ant.getFood()
                            ant.setFood((antFood*-1))
                            hill.addFood(antFood)
                            ant.setHaveFood(False)
                            print("Forager ant:", ant, "returned to its hill with food")

                elif(type(ant) is type(Warrior(910))):
                    prevX = ant.getCurrentCoord()[0]
                    prevY = ant.getCurrentCoord()[1]
                    self._grid[prevY][prevX].removeAnt(ant)
                    ant.move()
                    x = ant.getCurrentCoord()[0]
                    y = ant.getCurrentCoord()[1]
                    self._grid[y][x].addAnts(ant)

                    otherAnt = self.checkForForager(x,y,ant)
                    if otherAnt != None:
                        if otherAnt[0] == 0:
                            killChance = random.randrange(0,2)
                            if(killChance == 0):
                                self._grid[y][x].removeAnt(otherAnt[1])
                                otherHill = otherAnt[1].getHill()
                                otherHill.killAnt(otherAnt[1])
                                print("Warrior ant:", ant, "killed foreign forager: ", otherAnt[1])
                            else:
                                print("Forager ant:", otherAnt[1], "escaped")
                        #Its fighting a warrior ant
                        elif otherAnt[0] == 1:
                            killChance = random.randrange(0,5)
                            if(killChance == 0):
                                self._grid[y][x].removeAnt(otherAnt[1])
                                otherHill = otherAnt[1].getHill()
                                otherHill.killAnt(otherAnt[1])
                                print("Warrior ant encountered and fought other warrior")
                                print("Warrior ant:" ,ant, "killed foriegn ant:", otherAnt[1])
                            elif(killChance == 4):
                                self._grid[y][x].removeAnt(ant)
                                antHill = ant.getHill()
                                antHill.killAnt(ant)
                                print("Warrior ant encountered and fought other warrior")
                                print("Warrior ant:", ant, "died to foreign ant:", otherAnt[1])

                        #If warrior ant finds another ant Hill either attack it and kill hill or ant dies
                    if(self._grid[y][x].getHill() != None):
                        if(ant not in self._grid[y][x].getHill().getAnts()):
                            hillKillChance = random.randrange(0,5)
                            if(hillKillChance == 0):
                                self._grid[y][x].setHill(None)
                                self._hills.remove(hill)
                                print("Warrior:" , ant, "killed hill: ", hill)
                            else:
                                self._grid[y][x].removeAnt(ant)
                                antHill = ant.getHill()
                                antHill.killAnt(ant)
                                print("Warrior couldnt defeat ant hill and died")

                else:
                    antHill = ant.getHill()
                    rooms = antHill.getRooms()

                    x = ant.getCurrentCoord()[0]
                    y = ant.getCurrentCoord()[1]

                    if(antHill.getNumOfAnts() >= antHill.getMaxNum() or ant.getAlive() == False):
                        print("Cant make more ants at the max capacity")
                    else:
                        room = random.choice(rooms)
                        if(type(room) is type(WorkerRoom())):
                            newRoom = WorkerRoom()
                            antHill.addRoom(newRoom)
                            print("Worker:", ant, "made new room: ", room)
                        elif(type(room) is type(ForagerRoom())):
                            newRoom = ForagerRoom()
                            antHill.addRoom(newRoom)
                            print("Worker:", ant, "made new room: ", room)
                        else:
                            newRoom = WarriorRoom()
                            antHill.addRoom(newRoom)
                            print("Worker:" ,ant, "made new room: ", room)

                        amountOfFood = antHill.getFood()
                        if(amountOfFood !=0):
                            room = random.choice(antHill.getRooms())
                            if(type(room) == type(WorkerRoom())):
                                #make a worker ant
                                newAnt = WorkerRoom().newAnt(antHill.getIDCount())
                                newAnt.setHill(antHill)
                                newAnt.setCoord()
                                newAnt.setCurrentX(antHill.getXCoord())
                                newAnt.setCurrentY(antHill.getYCoord())
                                antHill.incIDCount()
                                antHill.addFood(-1)
                                antHill.addAnt(newAnt)
                                self._grid[y][x].addAnts(newAnt)

                                self._grid[y][x].removeAnt(ant)
                                ant.setDead()
                                print("Made new: ", newAnt)
                                print("Updated ant list:" , antHill.getAnts())

                            elif(type(room) == type(ForagerRoom)):
                                newAnt = ForagerRoom().newAnt(antHill.getIDCount())
                                newAnt.setHill(antHill)
                                newAnt.setCoord()
                                newAnt.setCurrentX(antHill.getXCoord())
                                newAnt.setCurrentY(antHill.getYCoord())
                                antHill.incIDCount()
                                antHill.addFood(-1)
                                antHill.addAnt(newAnt)
                                self._grid[y][x].addAnts(newAnt)
                                ant.setDead()
                                self._grid[y][x].removeAnt(ant)
                                print("Made new: ", newAnt)
                                print("Updated ant list:" , antHill.getAnts())
                            else:
                                newAnt = WarriorRoom().newAnt(antHill.getIDCount())
                                newAnt.setHill(antHill)
                                newAnt.setCoord()
                                newAnt.setCurrentX(antHill.getXCoord())
                                newAnt.setCurrentY(antHill.getYCoord())
                                antHill.incIDCount()
                                antHill.addFood(-1)
                                antHill.addAnt(newAnt)
                                self._grid[y][x].addAnts(newAnt)

                                self._grid[y][x].removeAnt(ant)
                                ant.setDead()
                                print("Made new: ", newAnt)
                                print("Updated ant list:" , antHill.getAnts())
            count = 0
            if(any(isinstance(ant, Forager) for ant in hill.getAnts())):
                count+=1
            if(count==0):
                x = hill.getXCoord()
                y = hill.getYCoord()
                self._grid[y][x].setHill(None)
                self._hills.remove(hill)
                print("Hill: ", hill, "was destroyed because there are no foragers")
                #Destroy the hill because there are no foragers

    def checkFood(self, x, y):
        if(self._grid[y][x].getFood() >0):
            return True
        else:
            return False

    def checkForForager(self,x,y, warrAnt):
        ants = self._grid[y][x].getAnts()
        warrTribe = warrAnt.getHill()
        warrAnts = warrTribe.getAnts()
        for ant in ants:
            if(ant not in warrAnts):
                if(type(ant) == type(Forager(909))):
                    return (0,ant)
                elif(type(ant) == type(Warrior(909))):
                    return (1,ant)









    def runCycle(self, n):
        run = True
        while(run == True):
            for i in range(n):
                self.cycle()
            n = int(input("Enter how many times you would like to run the cycle, enter 0 to quit: "))
            if(n == 0):
                run = False
                if(len(self._hills) == 1):
                    print("Only one ant hill left:", self._hills[0])
                    return

            else:
                for i in range(n):
                    self.cycle()





    def printData(self):
        cycleTimes = int(input("Enter how many times you would like to run the cycle: "))
        self.runCycle(cycleTimes)
        for hill in self._hills:
            print("Hill:" , hill)
            print("Food:" , hill.getFood())
            print("Ants: ", hill.getAnts())
        #print(self._grid)
        # count = 0
        # for i in self._grid:
        #     for j in i:
        #         print("AntHill:", j.getHill(),"Coords:", j.getXCoord(), j.getYCoord(), "Food of cell:", j.getFood())
        #         if(j.getHill() != None):
        #             print("AntHill Coord: ", j.getHill().getXCoord(), j.getHill().getYCoord())
        #             print(j.getHill().getRooms())
        #             print("Food of hill:", j.getHill().getFood())
        #             print(j.getHill().getAnts())
        #             print(j.getHill().getAnts()[0].getID(), j.getHill().getAnts()[1].getID(), j.getHill().getAnts()[2].getID())
        #         count+=1
        #
        # for i in self._hills:
        #     hill = i
        #     ants = hill.getAnts()
        #
        #     print(ants[0].getID(), ants[0].getStartCoord(), ants[1].getID(), ants[1].getStartCoord(), ants[1].getCurrentCoord(), ants[2].getID(), ants[2].getStartCoord(), ants[2].getCurrentCoord())
        # print(count)
