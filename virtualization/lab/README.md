# Container Lab

The objective of this lab is to "containerize" a web application. The outcomes
include:

- Ability to write image specifications (Dockerfiles) for web applications
- Working experience with popular containerization tools (Docker or Podman)
- Understanding the separation of concerns between application code and data
- A working example to use as inspiration for future applications

You will need to consult the [official documentation](https://docs.docker.com/reference/)
for most tasks.

## Getting Started

Please ensure some version of [Python3](https://www.python.org/downloads/) is
installed. This lab _may_ incidentally work on earlier versions, but no attempt
will be made to support them.

Install [Docker](https://docs.docker.com/engine/install/) and [Docker Compose](https://docs.docker.com/compose/install/)

> NOTE: Podman will likely work for this lab, but example commands are provided
> using the Docker CLI.

## Overview

This directory contains `server.py`, a basic HTTP server. The implementation of
this server is out of scope of the lab, and only basic modification to the file
will be needed to complete the tasks.

Each task will require the programmer to read the documentation and experiment
with various commands and configuration until the requirements are satisfied.
In other words, this is **not a tutorial**, and solutions will require you to
seek out information and iterate on a problem as if you were tasked with this
assignment in real life. This may be frustrating, but it leads to a superior
learning experience when compared to simply following instructions.

## 1. Getting Started

To start out, create a basic `Dockerfile`. The Dockerfile should add the
application source to the image and build successfully. Build your image with
the following command:

```bash
docker build . -t containerlabhttp
```

See the [Dockerfile Reference](https://docs.docker.com/reference/dockerfile/)
for more information.

## 2. Running the Application

Run the built image with:

```bash
docker run --rm -name=httpserver -p 8080:8080 containerlabhttp
```

You should see the following output:

> "server running on 127.0.0.1:8080"

Attempting to make a request to your server with:

```bash
curl -v localhost:8080/
```

will fail, however.

Your task is to fix the issue with the application and produce an image that
runs _both_ on your local machine _and_ inside a container. Consider how you
might be able to specify this behavior at runtime.

> Hint: Compare this [example app](https://github.com/docker/awesome-compose/blob/master/flask/app/app.py)
> to `server.py`

## 3. Compose File

Now that the application is running, it's a good time to write a Compose file.
The entries in this manifest correspond to Docker CLI commands, which allows
building and running an image to be reproducible. Additionally, a Compose file
saves a considerable amount of typing.

Create a file named `compose.yaml` in the root of the project. Your task is to
modify this file such that the following commands:

```bash
docker compose build
docker compose up -d
```

enable you to test the application with `curl` as before.

See the [Docker Compose Documentation](https://docs.docker.com/compose/) for
more information.

## 4. Data

You may have noticed a text file called `data.txt` created after the first
successful request to the server. Data generated and used by containers should
not be stored in its file system, but rather a form of external storage. This
task will require you to decide on the most appropriate way to store this file.

Modify `compose.yaml` to avoid storing `data.txt` in the container's filesystem

See [Storage](https://docs.docker.com/engine/storage/) for more information.

## 5. Security

By default, a container process runs as a privileged user (root). This can be
a cause for concern if an attacker were to compromise a running container. This
task requires you to run your process as a [non-root user](https://docs.docker.com/reference/dockerfile/#user).

> Hint: Consider what file permissions may be necessary to run the application
> as a non-root user.

## 6. Environment

It is common for developers to leverage Docker to target a specific environment,
such as `dev` or `prod`. In order to support this flexibility, applications
typically externalize their configuration using environment variables. Another
important use case is the inclusion of "debugging" tools or extra packages in a
development environment that would otherwise yield an unfavorably large image.

Modify either the Dockerfile, `compose.yaml`, or both to allow environment-aware
application behavior and/or builds.

See the [Docker Build Documentation](https://docs.docker.com/build/) for more
information.

> Hint: This approach may result in a more elegant solution to task #2, if you
> satisfied the requirements in some other way.

## Wrapping Up

This lab has covered the general considerations that an application programmer
has when working with containers. The Dockerfile and Compose file should serve
as a helpful reference when containerizing a new or existing project. Future
labs will cover more sophisticated uses of containers, such as networking and
deployment to a local Kubernetes cluster.

For this final task, consult the [best-practices](https://docs.docker.com/build/building/best-practices/)
documentation and make any desired adjustments to your Dockerfile you wish.

Congratulations on completing the container lab! I hope this has provided you
with valuable knowledge and experience that will serve you in your endeavours.
