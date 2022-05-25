# cxx-task
C++ calculator that finds the factors of a large number
This guide will walk you through the steps needed to build and run a C++ calculator on Rising Cloud

# 1. Install the Rising Cloud Command Line Interface (CLI)
In order to run the Rising Cloud commands in this guide, you will need to [install](https://risingcloud.com/docs/install) the Rising Cloud Command Line Interface. This program provides you with the utilities to setup your Rising Cloud Task or Web Service, upload your application to Rising Cloud, check the status of your app, and more.

# 2. Login to Rising Cloud using the CLI
Using a command line console (called terminal on Mac OS X and command prompt on Windows) run the Rising Cloud login command. The interface will request your Rising Cloud email address and password.

```risingcloud login```

# 3. Build your Application
You can get the code for the example from cxx-task repository on GitHub, just run git clone https://github.com/Rising-Cloud-Examples/cxx-task to get a local copy.  The files include; a header file (json.hpp), Makefile and the app itself (largeNumbers.cxx).

# 4. Initialize your Rising Cloud Task
On your console, navigate to your your project directory, and initialize a new task using the following command and replacing **$TASK** with your unique task name.  Use the **-s** flag to tell Rising Cloud this will be a serverless task.

```risingcloud init -s $TASK```

**NOTE** Your unique task name must be at least 12 characters long and consist of only alphanumeric characters and hyphens (-). This task name is unique to all tasks on Rising Cloud. A unique URL will be provided to you for sending jobs to your task including your task name.  If a task name is not available, the CLI will return with an error so you can try again.

This creates a **risingcloud.yaml** file in your project directory. This file will be used to configure the build instructions for your application.

# 5. Configure Your Build Parameters
In the **risingcloud.yaml**;

Change the build line to this:
```
build:
  - apt-get update
  - apt-get -y upgrade
  - apt-get install -y g++
  - apt-get install -y build-essential
  - make
```

Change the deps line to this:
```
deps:
  - chmod +x ./largeNumbers
```

Change your run line to this:
```run: ./largeNumbers```

# 6. Build and Deploy Your Rising Cloud Task
Use the **push** command to push your updated risingcloud.yaml to your Task on Rising Cloud.

```risingcloud push```

Use the **build** command to zip, upload, and build your app on Rising Cloud.

```risingcloud build```

Use the **deploy** command to deploy your app as soon as the build is complete.  Change **$TASK** to your unique task name.

```risingcloud deploy $TASK```

Alternatively, you could also use a combination to push, build and deploy all at once.

```risingcloud build -r -d```

Rising Cloud will now build out the infrastructure necessary to run and scale your application including networking, load balancing and DNS.  Allow DNS a few minutes to propogate and then your app will be ready and available to use!


# 7. Queue Jobs for your Rising Cloud Task

**Send jobs to your new app in the Portal**

- Log into your Rising Cloud Team: <u>[https://my.risingcloud.com/](https://my.risingcloud.com/)</u>
- Select your task from the Dashboard.
- Click on Jobs in the left menu.
- Click New Job Request.  
- Send the following request to your task, leave the curly brackets.

```{ "N":12345.6789 }```

Rising Cloud may will take a few moments to spin-up your and proces your request.  In the future it will learn from the apps usage patterns to anticipate usage, making instances available in advance of need, while also spinning down instances when not needed.  

Click the twisty to open up your Job, and then click Console to see your output

Congratulations! You’ve successfully used C++ on Rising Cloud!
