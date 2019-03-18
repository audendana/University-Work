# CS240
## Priority Queue with a call center simulation
- Use a priority queue to simulate a call center.
- 10% of calls have priority 1, 30% have priority 2, 60% have priority 3.
- A call's priority is randomly computed.
- The time taken to answer each call is 3-8 minutes.

- The basic algorithm for conducting the simulation is:
      for each minute during which calls are being accepted
        determine if a new call has arrived
        if a new call has arrived
            create a Call object and send it to the CallCenter
        update the CallCenter
      for each minute until all calls have been answered
        update the CallCenter



### Implementation
 * First define a priority queue using a linked list
 * PriorityQueue.h must implement
  1. Constructor and Deconstructor's
  2. enqueue() - add call to queue based on priority
  3. dequeue() - remove highest priority call from queue to be answered.
  4. getFront() - return highest priority call from queue.
  5. isEmpty()
  6. getSize()
  7. display()
