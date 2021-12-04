// Some functions doesn't require any inputs, e.g. Js.Math.random
// We need to provide parentheses () when calling those type of functions

let random1 = Js.Math.random(); // call the function
let random2 = Js.Math.random; // bind the function

Js.log2("Random 1: ", random1); // correct
Js.log2("Random 2: ", random2()); // correct
Js.log2("Random 3: ", random2); // wrong

// Js.log needs an input, but it doesn't provide return value (display text in terminal instead)
// We need to annotate unit as the return type
let debugInt = (varName: string, value: int): unit => {
 Js.log(varName ++ " is: " ++ string_of_int(value));
};

debugInt("My age", 25);