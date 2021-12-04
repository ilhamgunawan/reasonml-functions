// Add () unit unlabeled parameter when the last parameter has default value
let payment = (~principal, ~apr, ~years = 30, ()) => {
  let r = (apr /. 12.0) /. 100.0;
  let n = float_of_int(years * 12);
  let powerTerm = (1.0 +. r) ** n;
  principal *. (r *. powerTerm) /. (powerTerm -. 1.0);
};
let toFixed = Js.Float.toFixedWithPrecision; // bind original function to much shorter name
let apr = 5.0;
let principal = 10000.0;
let amount = payment(~apr, ~principal, ());
Js.log2("Amount per month $", toFixed(amount, ~digits = 2)); // use toFixed instead of original function