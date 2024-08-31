# Transactions

This module covers database transactions and what it means for a database to be
"ACID-compliant". The importance of understanding the concurrency control model
of a database cannot be understated. Write and Read anomalies can occur even at
a relatively low volume, and their effects can be disastrous and difficult to
debug.

It is strongly suggested to go through the [Concurrency](../concurrency) module
before working through these readings.

> NOTE: The optional readings in this section are excellent real-world examples
> of what can go wrong when a database technology is poorly understood. Of all
> the optional readings, these are of the **highest importance** in my opinion.

<!-- TODO: PostgreSQL lab on understanding isolation levels -->

## Objectives

- Develop a precise understanding of ACID
- Understand the implications of different isolation levels in databases
- Ability to evaluate the safety guarantees of a database from first principles

## Recommended Readings

- [Transactions: Myths, Surprises and Opportunities](https://www.youtube.com/watch?v=eo2EBdSbO10)
- [Isolation Levels in Modern SQL Databases](https://dev.to/franckpachot/series/25468) (Parts 1-7)

## Optional Readings

- Kleppmann (7.Transactions)
- [ACIDRain](http://www.bailis.org/papers/acidrain-sigmod2017.pdf)
- [Understanding Weak Isolation is a Serious Problem](http://www.bailis.org/blog/understanding-weak-isolation-is-a-serious-problem/)
- [BTC Stolen from Poloniex](https://bitcointalk.org/index.php?topic=499580)
- [How I stole roughly 100 BTC...](https://www.reddit.com/r/Bitcoin/comments/1wtbiu/how_i_stole_roughly_100_btc_from_an_exchange_and/)
- [Postgres Serializability Bug](https://github.com/gfredericks/pg-serializability-bug)
- [Jepsen Analysis: MongoDB 4.2.6](https://jepsen.io/analyses/mongodb-4.2.6) (Advanced)
