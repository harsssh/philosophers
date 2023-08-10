double ft_ceil(double x)
{
	double truncated;

	truncated = (double)(long)x;
	if (x > truncated)
		return truncated + 1.0;
	return truncated;
}

unsigned int ft_max(unsigned int a, unsigned int b)
{
	if (a < b)
		return b;
	return a;
}