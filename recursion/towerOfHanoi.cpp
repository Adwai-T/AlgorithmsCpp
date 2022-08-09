#include <iostream>

using namespace std;

void towerOfHanoi(int n, char fromPeg, char toPeg, char aux)
{
  //Base condition : If only one single disk left, move to dest peg.
  if(n == 1)
  {
    cout << "Move disk 1 from " << fromPeg << " to " << toPeg << endl;
    return;
  }

  //-- Move top n-1 peg from A to B using C as aux
  towerOfHanoi(n-1, fromPeg, aux, toPeg);

  //-- Move remaining pegs from A to C
  cout << "Move disk " << n << " from " << fromPeg << " to " << toPeg <<endl;

  //-- Move n-1 disk from B to C using A as aux
  towerOfHanoi(n-1, aux, toPeg, fromPeg);
}

int main()
{
  cout << "start" << endl;

  const char start = 'A';
  const char aux = 'B';
  const char dest = 'C';

  towerOfHanoi(3, start, dest, aux);  

  //-- Move the top
  
  cout << "end" << endl;
}

/*
* We solve this problem with recursion by thinking about the problem in reverse.
* We want the last disk be at on the destination tower, so we shift all the other disk to aux tower.
* For right now we will not consider how we moved the tower above the last disk to the aux tower, but it is just moved.
* So we have our biggest disk at it final position.
* Now we have a new problem with n-1 disk left, 
and previous starting tower as aux tower, and the previous aux tower as the new starting tower.
* We then repeat, we shift the all the disk but the biggest disk from current start tower to the aux.
* Then we shift the biggest disk from the new problem to the dest tower.
* At this point we have solved the problem for the last 2 disks in the original problem and 
we have the remaining disk in first tower or original start tower, forming a new problem of tower of hanoi with n-2 disk,
* We now do the same until there are no disk left in the original starting tower.

* Once we have solved the problem for 3 disk we can solve it for any number of disk by repeating the process.
*/