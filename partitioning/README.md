# Partitioning

Partitioning is a strategy to distribute data among a cluster of nodes. Certain
popular technologies, such as Redis and DynamoDB, use this technique to scale a
database instance to handle large amounts of data. Understanding this technique
helps programmers evenly distribute their data across nodes and avoid degraded
peformance due to "hot partitions".

> NOTE: The chapter on Partitioning in Kleppmann is marked as optional because
> the book is not free, but this is by far the superior treatment of database
> partitioning. If you have the means to acquire it, Designing Data-Intensive
> applications is worth the purchase for this subject.

## Objectives

- Understand the reason for database partitioning
- Familiarity with hash and range-key partition strategies
- Understand the interplay between partitions and secondary indexes

## Recommended Readings

- [Parallel Database Systems](https://15799.courses.cs.cmu.edu/fall2013/static/papers/dewittgray92.pdf) (Data Partitioning)
- [DynamoDB Secondary Indexes](https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/SecondaryIndexes.html)

## Optional Readings

- Kleppman (6.Partitioning)
- [3% of Twitter's Servers Dedicated to Justin Bieber](https://mashable.com/archive/justin-bieber-twitter)
- [The sweet spot for Cassandra secondary indexing](https://www.wentnet.com/blog/?p=77)

## Exercises

1. Suppose you decide to partition by: `hash(key) mod n`. This is a simple way
   of evently distributing keys among nodes. However, this approach has a flaw,
   can you identify it? (Hint: consider what happens when the number of nodes,
   `n`, changes).

2. Your colleague suggests a partitioning strategy in which a user's first name
   is hashed in order to determine the node that user's data will live on. Can
   you think of any downsides to this approach? Give an alternative approach if
   possible.

3. Discuss the drawbacks of using a local secondary index. When might this be a
   good idea over a global secondary index?

4. Suppose you are tasked with designing a content management system to support
   a large number of documents. Design a partitioning scheme that distributes
   data evenly, but still allows for efficient querying on attributes such as a
   date of publication, author, title, etc. (Hint: Is there a way we can employ
   _both_ hashing and range-key partitioning to achieve this?).
