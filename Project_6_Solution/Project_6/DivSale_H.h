#ifndef DivSale_H
#define DivSale_H
#include <iostream>

using namespace std;

class DivSale {
	private:
		double quarterSalesArray[4];
		double totalSales;

	public:
		
		void calculateAnnualSales(double q1Sales, double q2Sales, double q3Sales, double q4Sales){
			quarterSalesArray[0] = q1Sales;
			quarterSalesArray[1] = q2Sales;
			quarterSalesArray[2] = q3Sales;
			quarterSalesArray[3] = q4Sales;

			totalSales = (q1Sales + q2Sales + q3Sales + q4Sales);
		}

		double retrieveQuarterSales(int whichQuarter) {
			//Range must be between 0-4
			return quarterSalesArray[whichQuarter];
		
		}

		double getTotalSales() {return totalSales;}

};

#endif