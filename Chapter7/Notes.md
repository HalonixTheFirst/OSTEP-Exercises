Assume the following : 
1. Each job runs for the same amount of time.
2. All jobs arrive at the same time.
3. Once started, each job runs to completion.
4. All jobs only use the CPU (i.e., they perform no I/O)
5. The run-time of each job is known.  

Preemptive:  Jobs can be switched by the OS.[Does not cause starvation and cpu is utilized highly
but can 
cause overhead]  
Non Preemptive: Jobs must give up control by themselves.[Lower overhead but cput is not
fully utilized and can cause starvation.]  
Assume 1 : We can employ **FIFO**.
but if we relax 1 and all tasks dont run for the same amount of time
we can employ **SJF**  
If we relax 2 : SJF wont be optimal because _shorter processes might
still have to wait if they arrive even a little later than a 
larger process_ (Convoy effect)  
Now relax 3: If we can interrupt or preempt processes before
they complete we can implement another scheduler (**Shortest Job to completion First**)
**SJTC**   . It will check each time a new job arrives and run the one which has the 
least time left to complete and run that one.  
Response time is another problem. If we have to wait for a process finish
before another can respond its a bad deal. 
So what we can do is we can employ a time-shared scheduler.  
**Round Robin**
: A job runs for a time slice(called time quantum or scheduling quantum , its a fixed unit of time) 
The time slice must be a multiple of the interrupt timer.  
_The general technique of amortization is commonly used in systems
when there is a fixed cost to some operation. By incurring that cost less
often (i.e., by performing the operation fewer times), the total cost to the
system is reduced. For example, if the time slice is set to 10 ms, and the
context-switch cost is 1 ms, roughly 10% of time is spent context switching and is thus wasted. If we want to amortize this cost, we can increase
the time slice, e.g., to 100 ms. In this case, less than 1% of time is spent
context switching, and thus the cost of time-slicing has been amortized._  
Note : Fairness will not be good with turnaround time
and unfairness will not be good for response time.  
Relax assumption 4: If a process does some i/o . It can be stopped after it goes into blocked state and another 
process can run.  
Relax assumption 5: The os ofcourse doesn't know how long each process will run for so 
we can not do anything about it _yet_  .




