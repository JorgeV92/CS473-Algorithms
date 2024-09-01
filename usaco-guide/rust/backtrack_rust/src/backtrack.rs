use std::cmp::Ordering;

pub fn recurse_apples(index: usize, sum1: f64, sum2: f64, n: usize, weights: &[f64]) -> f64 {
    if index == n { return (sum1 - sum2).abs(); }
    let option1 = recurse_apples(index + 1, sum1 + weights[index], sum2, n, weights);
    let option2 = recurse_apples(index + 1, sum1, sum2 + weights[index], n, weights);
    
    match option1.partial_cmp(&option2) {
        Some(Ordering::Less) | Some(Ordering::Equal) => option1,
        Some(Ordering::Greater) => option2,
        None => option1,
    }

}

pub fun bitmask_apples(weights: &[f64]) -> f64 {
    let n = weights.len();
    let mut ans = f64::MAX;

    for mask in 0..(1 << n) {
        let mut sum1: f64 = 0.0;
        let mut sum2: f64 = 0.0;
        for i in 0..n {
            if mask & (1 << i) != 0 {
                sum1 += weights[i];
            } else {
                sum2 += weights[i];
            }
        }
        ans = f64::min(ans, (sum1 - sum2).abs());
    }
    ans
}