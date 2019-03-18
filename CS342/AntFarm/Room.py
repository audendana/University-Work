from abc import ABC, abstractmethod
from Ant import *
class Room(ABC):

    @abstractmethod
    def newAnt(self):
        pass

class WorkerRoom(Room):

    def newAnt(self, idNum):
        return Worker(idNum)


class ForagerRoom(Room):
    def newAnt(self, idNum):
        return Forager(idNum)

class WarriorRoom(Room):
    def newAnt(self, idNum):
        return Warrior(idNum)
