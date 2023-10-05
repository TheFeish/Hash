# Pseudocode
Hash (string s)

&nbsp; &nbsp; &nbsp; &nbsp; h1 ← 0

&nbsp; &nbsp; &nbsp; &nbsp; pow ← 257

&nbsp; &nbsp; &nbsp; &nbsp; for i ← 0 to s length do

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; h1 ← (h1 + s[i] ASCII code * pow) % (1e9 + 7)

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; pow ← (pow * 257) % (1e9 + 7)

&nbsp; &nbsp; &nbsp; &nbsp; h2 ← 0

&nbsp; &nbsp; &nbsp; &nbsp; pow ← 263

&nbsp; &nbsp; &nbsp; &nbsp; for i ← 0 to s length do

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; h2 ← (h2 + s[i] ASCII code * pow) % (1e9 + 9)

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; pow ← (pow * 263) % (1e9 + 9)

&nbsp; &nbsp; &nbsp; &nbsp; hash ← ""

&nbsp; &nbsp; &nbsp; &nbsp; random number generator 1 seed ← h1

&nbsp; &nbsp; &nbsp; &nbsp; random number generator 2 seed ← h2

&nbsp; &nbsp; &nbsp; &nbsp; for i ← 0 to 32 do

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; hash ← hash + random number generator 1 number from 0 to f

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; hash ← hash + random number generator 2 number from 0 to f

&nbsp; &nbsp; &nbsp; &nbsp; return hash
# Testing
### Input and outup size
Input of any size can be hashed and output is always a 256 bit number in hexadecimal format:
* Hash of a 1 character string:
40344f3f1c0ea114cef5ace64671d745b842e43bc0eff51bd63a0b13d98dfd8e
* Hash of a 10000 chacarter string:
a16fa28de23ff7d4ea9648a984e380fa69c6c0d0c5ffc197e1b4aa3a4cb9bef1

### Hash output is deterministic
For instance hashing an empty file will always return
8899bbdd99dd88dd6699aa667744ee00ff446677cccc88779966eedd115511aa

### Hashing performance
Hashing times rise somewhat linearly.
Tested by hashing different number of lines from constitution of Lithuania:
![lineHashing](https://github.com/TheFeish/Hash/assets/113859423/1fd676e4-48a3-4e93-b791-c7ea084d81be)


### Collision resistance
0 collisions found by testing 100000 pairs of random text strings - 25000 of 10, 100, 500 and 1000 characters long.

### Avalanche effect
100000 pairs of string with 1 character difference between them - 25000 of 10, 100, 500 and 1000 characters long where tested:
* Bitwise difference:
	* Average: 50.01%
	* Minimum: 36.72%
	* Maximum: 63.28%
* Hexwise difference:
	* Average: 93.77%
	* Minimum: 78.13%
	* Maximum: 100%

### Conclusion
By this limited testing it can be concluded that: 
* The hashing function can process inputs of variable length and output a 256 bit number in hexadecimal form.
* Hashing times rise somewhat linearly while increasing input size.
* The hashing function is somewhat collision resistant as no collisions were found while testing 100000 pairs of random strings.
* While hashing function's hexwise difference while hashing random strings with 1 character difference is high, bitwise difference is a bit low as difference equal or above 50% is preferred.
