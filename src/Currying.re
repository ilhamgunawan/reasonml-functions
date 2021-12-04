let avg = (a: float, b: float): float => {
  (a +. b) /. 2.0;
};
Js.log2("Average of 3 and 4: ", avg(3.0, 4.0));
Js.log2("Average of 3 and undefined: ", avg(3.0));
Js.log("------------------------------------------");



// Example of currying
// call is a function that receives 4 string inputs and return a string value
let call = (country: string, area: string, number: string): string => {
  {j|$country $area $number|j};
};
let callKim = call("49", "030", "118 99"); // call received all valid inputs, callKim should be a string value
let callGermany = call("049"); // call is missing area and number, callGermany should return function
let callBerlin = call("049", "030") // call is missing number, callBerlin should return function
Js.log2("Call Kim: ", callKim);
Js.log2("Call Germany: ", callGermany("030", "111 66"));
Js.log2("Call Berlin: ", callBerlin("123 11"));
