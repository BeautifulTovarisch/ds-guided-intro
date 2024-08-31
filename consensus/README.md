# Consensus

Consensus is broadly about getting nodes in a distributed system to agree upon a
view of some state. Technologies such as Zookeeper, implement algorithms which
ensure consensus can be achieved even in the presences of failures. This module
covers the basics of consensus.

<!-- TODO: Lab with zookeeper (leader election?). This will be difficult for me
to put together... -->

It is strongly recommended to complete the [Clocks](../clocks) and [Concurrency](../concurrency)
modules before approaching the material in this section.

## Objectives

- High-level understanding of consensus in a distributed system
- Rationale behind achieving consensus
- Drawbacks of existing consensus algorithms
- Identify workloads for which consensus is required for correctness

## Recommended Readings

- Tanenbaum (5.4.1, 5.4.2, 5.4.3, 5.4.4, 8.2.3, 8.3.4, 8.5)

## Optional Readings

- Kleppmann (9.Distributed Transactions and Consensus)
- [How to do distributed locking](https://martin.kleppmann.com/2016/02/08/how-to-do-distributed-locking.html)
- [Is Redlock safe?](http://antirez.com/news/101)
- [The fallacy of distributed transactions](https://ayende.com/blog/167362/the-fallacy-of-distributed-transactions)
- [Paxos Made Simple](https://lamport.azurewebsites.net/pubs/paxos-simple.pdf)
