# Consistency

Consistency is a widely discussed topic when choosing a datastores for a system.
Unfortunately, many of these conversations are heavily influenced by marketing
material of database vendors and/or technology enthusiasts on social media. It
is critical for a programmer to develop rigorous consistency models to make the
right choice for their workload.

<!-- TODO: Lab with async Postgres replication and/or Redis cache -->

It is strongly recommended to complete the [Replication](../replication) module
before workging through these readings.

## Objectives

- Identify the main consistency models found in distributed systems
- Understand the tradeoffs between different consistency guarantees
- Understand the CAP theorem, and its relevance to modern systems
- Ability to apply an appropriate consistency model to a workload

## Recommended Readings

- Tanenbaum (7.2, 7.3)
- [Consistency Baseball](https://www.microsoft.com/en-us/research/wp-content/uploads/2011/10/ConsistencyAndBaseballReport.pdf) (Sections 1 & 2)
- [Please stop calling databases CP or AP](https://martin.kleppmann.com/2015/05/11/please-stop-calling-databases-cp-or-ap.html)

## Optional Readings

- Kleppmann (9.Consistency Guarantees, 9.Linearizability)
- [Jepsen: MongoDB stale reads](https://aphyr.com/posts/322-call-me-maybe-mongodb-stale-reads)
- [A Critique of the CAP Theorem](https://www.cl.cam.ac.uk/research/dtg/archived/files/publications/public/mk428/cap-critique.pdf)
- [Perspectives on the CAP Theorem](https://groups.csail.mit.edu/tds/papers/Gilbert/Brewer2.pdf)

## Exercises

1. Many NoSQL proponents claim that _eventual consistency_ is only achievable if
   transactions are abandoned? Can you think of a counter-example to this claim?

2. Give an example of when _read-your-writes_ consistency would prevent a poor
   user experience.
