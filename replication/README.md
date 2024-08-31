# Replication

Replication refers to the general condition in which copies of data are stored
in different locations. This technique, along with partitioning, allows a data
system to scale its throughput and provide a degree of fault-tolerance. On the
other hand, many subtle issues can arise when replication is poorly understood.

<!-- TODO: Lab with postgres single-leader replication -->

> NOTE: The chapter on Replication in Kleppmann is marked as optional because
> the book is not free, but this is by far the superior treatment of database
> replication. If you have the means to acquire it, Designing Data-Intensive
> applications is worth the purchase for this subject.

## Objectives

- Understand the motivations behind data replication
- Identify tradeoffs between different replication strategies
- Establish a conceptual foundation for understanding modern distributed DBs

## Recommended Readings

- Tanenbaum (7.1, 7.6)
- [Notes on Distributed Databases](https://dominoweb.draco.res.ibm.com/reports/RJ2571.pdf) (1.2, 1.3)

## Optional Readings

- Kleppmann (5.Replication)
- [GitHub availability this week](https://github.blog/news-insights/the-library/github-availability-this-week/)
- [Downtime last Saturday](https://github.blog/news-insights/the-library/downtime-last-saturday/)
