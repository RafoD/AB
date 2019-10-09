#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

vector<ulli> sieve(ulli n)
{
    // Create a boolean vector "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
    vector<bool> prime(n+1,true);

    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);

    for (ulli p=2; p<=m; p++)
    {

        // If prime[p] is not changed, then it
        // is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (ulli i=p*2; i<=n; i += p)
            prime[i] = false;
        }
    }

    // push all the primes into the vector ans
    vector<ulli> ans;
    for (int i=0;i<n;i++)
        if (prime[i])
            ans.push_back(i);
    return ans;
}

// Used to remove zeros from a vector using
// library function remove_if()
bool isZero(ulli i)
{
    return i == 0;
}

vector<ulli> sieveRange(ulli start,ulli end)
{
    // find primes from [0..start] range
    vector<ulli> s1 = sieve(start);

    // find primes from [0..end] range
    vector<ulli> s2 = sieve(end);

    vector<ulli> ans(end-start);

    // find set difference of two vectors and
    // push result in vector ans
    // O(2*(m+n)-1)
    set_difference(s2.begin(), s2.end(), s1.begin(),
                             s2.end(), ans.begin());

    // remove extra zeros if any. O(n)
    vector<ulli>::iterator itr =
                    remove_if(ans.begin(),ans.end(),isZero);

    // resize it. // O(n)
    ans.resize(itr-ans.begin());

    return ans;
}

// Driver Program to test above function
int main(void)
{
    ulli start = 50;
    ulli end = 100;
    vector<ulli> ans = sieveRange(start,end);
    for (auto i:ans)
        cout<<i<<' ';
    return 0;
}
