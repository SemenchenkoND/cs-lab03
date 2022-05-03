#include <math.h>
#include <iostream>
#include <vector>
#include "histogram.h"
using namespace std;

vector<double> input_numbers(size_t number_count)
{
	vector<double> result(number_count);
	for (size_t i = 0; i < number_count; i++)
	{
		cin >> result[i];
	}
	return result;
}


void find_minmax(const vector <double>& numbers, double& min, double& max)
{
	min = numbers[0];
	max = numbers[0];

	for (double number : numbers)
	{
		if (number < min)
		{
			min = number;
		}

		if (number > max)
		{
			max = number;
		}
	}

}

vector <size_t> make_histogram(const vector <double>& numbers, size_t bin_count)
{
	double min, max;
	find_minmax(numbers, min, max);

	vector<size_t> bins(bin_count, 0);
	double bin_size = (max - min) / bin_count;

	for (double number : numbers)
	{
		bool found = false;
		for (size_t j = 0; j < (bin_count - 1) && !found; j++)
		{
			auto low = min + j * bin_size;
			auto hight = min + (j + 1) * bin_size;

			if ((low <= number) && (number < hight)) {
				bins[j]++;
				found = true;
			}
		}
		if (!found) {
			bins[bin_count - 1]++;
		}
	}
	return bins;
}

void show_histogram_text(vector <size_t> bins)
{
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

	size_t max_bin = bins[0];
	for (double bin : bins)
	{
		if (bin > max_bin)
		{
			max_bin = bin;
		}
	}

	size_t maxhigth;
	if (max_bin < 76)
		maxhigth = max_bin;
	else
		maxhigth = 76;
	for (double bin : bins)
	{
		size_t height = bin;
		// проверить масштабирование(пересчитать height)

		if (height > MAX_ASTERISK)
		{
			height = MAX_ASTERISK * (static_cast<double> (bin) / max_bin);
		}


		if (bin < 100) {
			cout << " ";
		}

		if (bin < 10) {
			cout << " ";
		}
		for (size_t i = 0; i < maxhigth - height; i++)
			cout << " ";

		for (size_t i = 0; i < height; i++)
		{
			cout << "*";
		}
		cout << "|" << bin << endl;

	}

}


int main()
{
	//ввод данных
	size_t number_count;
	cerr << "Enter number count: ";
	cin >> number_count;

	cerr << "Enter numbers: ";
	const auto numbers = input_numbers(number_count);

	size_t bin_count;
	cerr << "Enter bin count: ";
	cin >> bin_count;

	//расчет данных
	const auto bins = make_histogram(numbers, bin_count);

	//вывод гистограммы
	show_histogram_svg(bins);

	return 0;
}