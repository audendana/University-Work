import random
from AntHill import *
from Room import *
class Queen:
    def __init__(self, grid):
        self._grid = grid
        self._antHill = None


    def selectLocation(self):
        x = random.randrange(0,10)
        y = random.randrange(0,10)
        print(self._grid[y][x])
        if(self._grid[y][x].getHill() == None):
            self._antHill = AntHill(x,y)
            print(x,y)
            return self
        else:
            unique = False
            while(unique == False):
                x = random.randrange(0,10)
                y = random.randrange(0,10)

                if(self._grid[y][x].getHill() == None):
                    self._antHill = AntHill(x,y)
                    print(x,y)
                    unique = True
                    return self

    def addInitRooms(self):
        self._antHill.addRoom(WorkerRoom())
        self._antHill.addRoom(ForagerRoom())
        self._antHill.addRoom(WarriorRoom())
        return self

    def addInitFood(self):
        self._antHill.addFood(1)
        return self

    def addInitAnts(self, idCount):
        workerAnt = self._antHill.getRooms()[0].newAnt(idCount)
        workerAnt.setHill(self._antHill)
        workerAnt.setCoord()
        workerAnt.setCurrentX(self._antHill.getXCoord())
        workerAnt.setCurrentY(self._antHill.getYCoord())
        idCount+=1
        foragerAnt = self._antHill.getRooms()[1].newAnt(idCount)
        foragerAnt.setHill(self._antHill)
        foragerAnt.setCoord()
        foragerAnt.setCurrentX(self._antHill.getXCoord())
        foragerAnt.setCurrentY(self._antHill.getYCoord())
        idCount+=1

        warriorAnt = self._antHill.getRooms()[2].newAnt(idCount)
        warriorAnt.setHill(self._antHill)
        warriorAnt.setCoord()
        warriorAnt.setCurrentX(self._antHill.getXCoord())
        warriorAnt.setCurrentY(self._antHill.getYCoord())
        idCount+=1
        self._antHill.setIDCount(idCount)

        self._antHill.addAnt(workerAnt)
        self._antHill.addAnt(foragerAnt)
        self._antHill.addAnt(warriorAnt)

        return self


    def build(self):
        return self._antHill
