class Cell:
    def __init__(self,x,y):
        self._hill = None
        self._food = 0
        self._ants = []
        self._xCoord = x
        self._yCoord = y


    def setHill(self, hillType):
        self._hill = hillType

    def getHill(self):
        return self._hill

    def setFood(self, additionalFood):
        self._food += additionalFood

    def getFood(self):
        return self._food

    def addAnts(self, ant):
        self._ants.append(ant)

    def removeAnt(self, ant):
        if(ant in self._ants):
            self._ants.remove(ant)

    def getAnts(self):
        return self._ants

    def getXCoord(self):
        return self._xCoord

    def getYCoord(self):
        return self._yCoord

    def addAnt(self, ant):
        self._ants.append(ant)
    def getAnts(self):
        return self._ants

    def getNumOfAnts(self):
        return len(self._ants)
