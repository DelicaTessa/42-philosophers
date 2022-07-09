# philosophers
[![tclement's 42 Philosophers Score](https://badge42.vercel.app/api/v2/cl59lbrtc003009jqom2qgm4z/project/2202410)](https://github.com/JaeSeoKim/badge42)<br>
***This project focuses on the basics of threading a process and how to work on the same memory space. We learned how to make `threads` and discover the `mutex`***

## Project requirements

- A number of philosophers are sitting at a round table doing one of three things: `eating`, `thinking` or `sleeping`. 
  
- The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table. As spaghetti is difficult to eat with a single fork, it is assumed that a philosopher eats with two forks, one for each hand.

- The philosophers must never be starving. Every philosopher needs to eat. Philosophers don’t speak with each other. Philosophers don’t know when another philosopher is about to die. 

- Each time a philosopher has finished eating, he will drop his forks and start sleeping. When a philosopher is done sleeping, he will start thinking. The simulation stops when a philosopher dies.

- One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
  
- To avoid philosophers duplicating forks, you should protect the forks state with a `mutex` for each of them.
  
- Each philosopher should be a `thread`.


## How to test

- These parameters are required in order when running the executable: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `number_of_times_each_philosopher_must_eat(optional)`
- Do not test with more than 200 philosophers
- Do not test with `time_to_die` `time_to_eat` `time_to_sleep` under 60ms
- Test with `5 800 200 200`, no one should die
- Test with `5 800 200 200 7`, the simulation should stop when all the philosophers have eaten at least 7 times each

> Run the following commands:

```shell
$ git clone https://github.com/DelicaTessa/42-philosophers
$ cd 42-philosophers && philo
$ make
$ ./philo 5 800 200 200
```
