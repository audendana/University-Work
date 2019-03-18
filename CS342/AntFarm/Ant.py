import random
from Room import *

class Ant:
    def __init__(self, idNum):
        self._alive = True
        self._ID = ""
        self._idNum = idNum
        self._antHill = None
        self._xStart = -1
        self._yStart = -1
        self._currentX = -1
        self._currentY = -1

    def setCoord(self):
        self._xStart = self._antHill.getXCoord()
        self._yStart = self._antHill.getYCoord()

    def setHill(self, hill):
        self._antHill = hill
    def getHill(self):
        return self._antHill

    def getStartCoord(self):
        return (self._xStart, self._yStart)


    def setCurrentX(self, x):
        self._currentX = x

    def setCurrentY(self, y):
        self._currentY = y

    def getCurrentCoord(self):
        return (self._currentX, self._currentY)


class Worker(Ant):
    def __init__(self, idNum):
        super().__init__(idNum)
        self.setID()

    def setID(self):
        self._ID = "WO"+str(self._idNum)

    def getID(self):
        return self._ID

    def setDead(self):
        self._alive = False

    def getAlive(self):
        return self._alive

    def makeRoom(self):
        # 0 = WorkerRoom, 1 = ForagerRoom, 2 = WarriorRoom
        randRoom = random.randrange(0,3)
        if(randRoom == 0):
            return WorkerRoom()
        elif(randRoom == 1):
            return ForagerRoom()
        else:
            return WarriorRoom()



class Forager(Ant):
    def __init__(self, idNum):
        super().__init__(idNum)
        self._foodAmount = 0
        self._food = False
        self.setID()



    def setID(self):
        self._ID = "F"+str(self._idNum)

    def getID(self):
        return self._ID

    def search(self):
        self.move()

    def setFood(self, foodAmount):
        self._foodAmount += foodAmount
    def getFood(self):
        return self._foodAmount

    def haveFood(self):
        return self._food
    def setHaveFood(self, val):
        self._food = val

    def returnToHill(self):
        xStart = self.getStartCoord()[0]
        yStart = self.getStartCoord()[1]

        xCur = self.getCurrentCoord()[0]
        yCur = self.getCurrentCoord()[1]

        xDis = xCur - xStart
        yDis = yCur - yStart

        if(xDis > 0):
            self.moveLeft()
        elif(xDis < 0):
            self.moveRight()

        if(yDis > 0):
            self.moveUp()
        elif(yDis < 0):
            self.moveDown()

    def moveUp(self):
        self._currentY-=1

    def moveDown(self):
        self._currentY+=1

    def moveLeft(self):
        self._currentX-=1
    def moveRight(self):
        self._currentX+=1

    def move(self):
        if(self._currentX == 0 and self._currentY == 0):
            #top left corner cant move up or left, 0 = down, 1 = right
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY += 1
            else:
                self._currentX+=1

        elif(self._currentX == 19 and self._currentY ==0):
            #top right corner cant move up or right 0= down, 1= left
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY+=1
            else:
                self._currentX-=1

        elif(self._currentX == 19 and self._currentY == 19):
            #bot right corner cant move down or right 0 = up, 1 =left
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY-=1
            else:
                self._currentX-=1

        elif(self._currentX == 0 and self._currentY == 19):
            #bot left corner cant move down or left 0 = up, 1 = right
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY-=1
            else:
                self._currentX+=1

        elif(self._currentY == 0):
            # top row 0 = down, 1= left, 2= right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY+=1
            elif(movement ==1):
                self._currentX-=1
            else:
                self._currentX+=1

        elif(self._currentY == 19):
            # bot row 0 = up, 1= left, 2 = right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentX-=1
            else:
                self._currentX+=1
        elif(self._currentX == 0):
            # left side 0 = up, 1= down, 2= right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentY+=1
            else:
                self._currentX+=1
        elif(self._currentX == 19):
            # right side 0 = up, 1= down, 2= left
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentY+=1
            else:
                self._currentX-=1
        else:
            print("in the middle")
            movement = random.randrange(0,4)
            if(movement == 0):
                self._currentY-=1
            elif(movement==1):
                self._currentY+=1
            elif(movement==2):
                self._currentX-=1
            else:
                self._currentX+=1
        #in the middle 0 = up, 1 = down, 2 = left, 3 = right









class Warrior(Ant):
    def __init__(self, idNum):
        super().__init__(idNum)
        self.setID()

    def setID(self):
        self._ID = "WA"+str(self._idNum)

    def getID(self):
        return self._ID

    def move(self):
        if(self._currentX == 0 and self._currentY == 0):
            #top left corner cant move up or left, 0 = down, 1 = right
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY += 1
            else:
                self._currentX+=1

        elif(self._currentX == 19 and self._currentY ==0):
            #top right corner cant move up or right 0= down, 1= left
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY+=1
            else:
                self._currentX-=1

        elif(self._currentX == 19 and self._currentY == 19):
            #bot right corner cant move down or right 0 = up, 1 =left
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY-=1
            else:
                self._currentX-=1

        elif(self._currentX == 0 and self._currentY == 19):
            #bot left corner cant move down or left 0 = up, 1 = right
            movement = random.randrange(0,2)
            if(movement == 0):
                self._currentY-=1
            else:
                self._currentX+=1

        elif(self._currentY == 0):
            # top row 0 = down, 1= left, 2= right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY+=1
            elif(movement ==1):
                self._currentX-=1
            else:
                self._currentX+=1

        elif(self._currentY == 19):
            # bot row 0 = up, 1= left, 2 = right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentX-=1
            else:
                self._currentX+=1
        elif(self._currentX == 0):
            # left side 0 = up, 1= down, 2= right
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentY+=1
            else:
                self._currentX+=1
        elif(self._currentX == 19):
            # right side 0 = up, 1= down, 2= left
            movement = random.randrange(0,3)
            if(movement == 0):
                self._currentY-=1
            elif(movement ==1):
                self._currentY+=1
            else:
                self._currentX-=1
        else:
            movement = random.randrange(0,4)
            if(movement == 0):
                self._currentY-=1
            elif(movement==1):
                self._currentY+=1
            elif(movement==2):
                self._currentX-=1
            else:
                self._currentX+=1
        #in the middle 0 = up, 1 = down, 2 = left, 3 = right
