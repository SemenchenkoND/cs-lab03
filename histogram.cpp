#include "histogram.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;

const auto RECT_STROKE = "red";
const auto RECT_FILL = "black";
*/
void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y
        << "' width='" << width << "' height='" << height
        << "' stroke='" << stroke << "' fill='" << fill << "'/>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<
        "</text>";
}

void show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 370;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 0;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto RECT_STROKE = "red";
    const auto RECT_FILL = "black";

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins)
    {
        if (bin < 100) {
            const double bin_width = BLOCK_WIDTH * bin;
            const double text_width = IMAGE_WIDTH - bin_width - BLOCK_WIDTH - 30;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(text_width, top, bin_width, BIN_HEIGHT, RECT_STROKE, RECT_FILL);
            top += BIN_HEIGHT;
        }
        else {
            const double bin_width = BLOCK_WIDTH * bin;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, TEXT_LEFT, BIN_HEIGHT, RECT_STROKE, RECT_FILL);
            top += BIN_HEIGHT;
        }
    }
    svg_end();
}

void svg_end()
{
    cout << "</svg>\n";
}
