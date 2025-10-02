# Change Calculator

You need to implement the logic of change calculation. All needed cases should be covered by 
unit tests and the solution has to be developed according to TDD (Test-Driven Development).
 Let’s imagine you are a salesman, and you need to return the change to a buyer or tell this 
person that you don’t have it and the payment can be done only using a credit card. For 
simplicity you have only the following possible nominal values: 100, 50, 10, 5, 2, and 1. You 
might not have all nominal values at your checkout point, e.g. you don’t have coins with the 
nominal value 5. At the same time, you might have several coins with the same nominal value, 
e.g. 25 coins with the nominal value 1.
 Implement a function that can tell if the needed amount of change can be returned to a buyer 
and if it can also return the list of coins that will make it.

 Example
 For instance, you have the following coins 5, 3, and 1. If I ask you about the change that equals 
to 4 you can return it and the coins will be 3 and 1. However, you cannot return the change 
that equals to 2.
