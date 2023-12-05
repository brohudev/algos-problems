def maximize_revenue_dp(prices):
    n = len(prices)
    memo = [None] * n  # Initialize memoization table with None

    def dp(remaining_quantity):
        if remaining_quantity == 0:
            return 0, []

        if memo[remaining_quantity] is not None:
            return memo[remaining_quantity]

        max_revenue = 0
        best_solution = []
        
        for quantity in range(1, remaining_quantity + 1):
            current_revenue, current_solution = dp(remaining_quantity - quantity)
            current_revenue += prices[quantity]

            if current_revenue > max_revenue:
                max_revenue = current_revenue
                best_solution = [quantity] + current_solution

        memo[remaining_quantity] = max_revenue, best_solution
        return max_revenue, best_solution
    _, solution = dp(n - 1)
    return solution


input_line = input()

# Split the input string into a list of ints
prices = input_line.split()
int_prices = [int(num) for num in prices]
# print result
print(maximize_revenue_dp(int_prices))
