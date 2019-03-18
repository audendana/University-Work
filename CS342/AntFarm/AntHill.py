class AntHill:
    def __init__(self, x, y):
        self._ants = []
        self._rooms = []
        self._storedFood = 0
        self._xCoord = x
        self._yCoord = y
        self._idCount = 0
        self._maxAntsNum = 20

    def getXCoord(self):
        return self._xCoord


    def getYCoord(self):
        return self._yCoord

    def addRoom(self, room):
        self._rooms.append(room)

    def addAnt(self, ant):
        self._ants.append(ant)

    def killAnt(self, ant):
        self._ants.remove(ant)

    def getAnts(self):
        return self._ants

    def setIDCount(self, idCount):
        self._idCount = idCount

    def getIDCount(self):
        return self._idCount

    def incIDCount(self):
        self._idCount+=1


    def addFood(self, foodAmount):
        self._storedFood += foodAmount

    def getFood(self):
        return self._storedFood

    def getNumOfAnts(self):
        return len(self._ants)

    def getRooms(self):
        return self._rooms

    def getMaxNum(self):
        return self._maxAntsNum
