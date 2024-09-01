use std::io;
use std::io::Write;
mod backtrack;

fn main() {
    let mut input = String::new();
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let n: usize = input.trim().parse().expect("Failed to parse n");

    let mut weights = Vec::with_capacity(n);
    input.clear();
    io::stdin().read_line(&mut input).expect("Failed to read weights");

    for weight in input.trim().split_whitespace() {
        let weight: f64 = weight.parse().expect("Failed to parse weight");
        weights.push(weight);
    }

    let res = backtrack::recurse_apples(0, 0.0, 0.0, n, &weights);
    println!("{}", res);
}
