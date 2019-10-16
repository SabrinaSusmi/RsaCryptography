# RsaCryptography
RSA is the most widespread and used public key algorithm for encrypting messages. It is popular because of it is very hard to crack as its encryption is based on the difficulty of factoring large integers.The RSA algorithm can be used for both public key encryption and digital signatures. 
RSA involves a public key and a private key. The public key can be known by everyone and anyone can use it for encrypting messages. And the encrypted message can only be decrypted only by someone who knows the private key or has knowledge about the prime numbers used to generate the public keys. The public key is represented by the integers n and e; and, the private key, by the integer d.

RSA algorithm:
1.At first choose two distinct prime numbers p and q. They must be kept secret.
2.Compute public key N=p*q.
3.Compute the Euler totient function φ(n) = (p − 1)*(q − 1).
4.Choose e(public key). There are two conditions while choosing e: 1<e<φ(n) and e has to be co-prime with N and φ(n).
5.Choose d(private key). While choosing d we have to make sure that 1<d<φ(n) and ed = 1 mod φ(n).

Encryption process:
1.The message will be encrypted character by character.
2.Assume the positional value of a character is m.
3.Encryption: c=(m^e) mod N.
4.Now we have to convert the positional value c to its relevant character.
5.The character is encrypted.

Decryption process:
1.The encrypted will be decrypted character by character as before.
2.Assume the positional value of a character is c.
3.Decryption: m=(c^d) mod N.
4.Then convert the positional value m to its relevant character.
5.The character is decrypted.

In this way the RSA algorithm works.

