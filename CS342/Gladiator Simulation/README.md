# CS342 Design Patterns
## Fall 2018
### PROJECT 4 README FILE


### Driver Code and Test Files
* gladiators.json

## Description

For our final assignment we are going to simulate the gladiatorial contests in the Colosseum in Rome. The game will begin with you reading a json file that contains a list of competitors. Each competitor will compete in the arena in a tournament style battle until there is only one left. An audience will boo, cheer, and ultimately decide the fate of each contender.

## Part A - Creating your participants

### Gladiator

The gladiator data will consists of name (string), age (int), birthplace (string), and health (int 0-100). The data will be stored in a json file in the following format:
[
        {name: ‘ceasar’, age: 56, birthplace: ‘Rome’, health: 50}
...
]
The outcome of the gladiatorial tests should be based on an algorithm of your choosing with 2 requirements:
* The result should not be entirely random. You can factor in previous wins, the health attribute, or whatever else you want, but there should be some weighted factor.
* Matches should produce several events that determine the outcome of the match.

### Audience

Next you will need to create an audience. The audience class observes the Gladiators as they go through the gladiatorial games, giving cheers, boos, or gasps as events occur in each match. You should create an audience of at least 100 audience objects that register as observers of the gladiator. The gladiator then ‘notifies’ the audience whenever an event occurs. There are 3 possible event types:
* The gladiator is harmed (loses health)
* The gladiator wins a match
* The gladiator loses a match

### Response

In addition to the audience class, you should create at least 3 audience member response strategies which will determine how different audience members respond to an event. For example, a negative response type would produce the following results:
* The gladiator is harmed (loses health) produces cheers
* The gladiator completes a task produces boos
* The gladiator fails a task produces cheers

Another response type, for example positive:
* The gladiator is harmed (loses health) produces boos
* The gladiator completes a task produces cheers
* The gladiator fails a task produces gasps

The response strategies should be contained in their own classes and should be assigned randomly to each audience object.

Each audience member randomly chooses one of the gladiators during the match to observe and respond to. The response strategy for each audience member should be updated with a new response strategy for each match.

## Part B - The Arena
Once you have your gladiators and your audience set up, the gladiatorial tournament can begin.

### Arena
The Arena class will hold all the audience members, gladiators, and battle logic.

Your gladiators will be put into the arena and compete in battle. Your logic will be to retrieve the next two gladiators from the pool of gladiators and have them battle until one reaches zero health. Then the audience will decide if the loser should have another chance with a thumbs up or thumbs down vote.

Each audience member will choose thumbs up or thumbs down based on any algorithm of your choosing.
* If the majority of audience members give the thumbs up, the gladiator will be placed back in the pool of gladiators and live to fight another round. :bulb: You will need to reset the gladiator's health.
* Otherwise, the gladiator is deleted.

## Project Requirements
In this assignment, you will use the Strategy and Observer Patterns. How each pattern will be used is explained below.
* Observer
   * The gladiator class should follow the design pattern requirements in the observer pattern for the subject.
   * The audience members should follow the observer pattern and must have an update method that takes an event type as a parameter.
* Strategy
   * You may use either classes or functions, but you should implement at least 3 different response types that can be passed to the audience members. All should share the same interface for responding with slightly different results.


### PROJECT IMPLEMENTATION DETAILS
  * Observer Pattern: Gladiator is the subject and has many audience member observers.
  * Strategy Pattern: Each audience member is assigned a random strategy response(Positive, Negative, Neutral).
    Responses are generated when gladiator notifies audience of event.
  * Fighting Algorithm rewards gladiators between ages 20-40, for previous wins, health and random bonus.
  * Gladiators are stored in a queue to prevent gladiators from fighting repeat matches.
  * Voting: Each audience member can vote up or down randomly per match. Votes are summed if the total is greater than half
    the audience members an encore round begins.
