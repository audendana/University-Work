from Universe import *
from Star import *
from Planet import *
from Probe import *


def main():
    num = 1025/3

    universe = Universe(int(num),int(num),int(num))
    universe.generateUniverse()
    probe = Probe(universe.getStars())
    probe.startPoint()
    probe.path()
    universe.printData()
    print()
    probe.printData()


if __name__ == "__main__":
    main()
