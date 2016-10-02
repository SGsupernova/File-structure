#ifndef __STOCK_TEST__
#define __STOCK_TEST__

#include "../classes/class_stock.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void stockTest (int n = 10) {
	ifstream ifs ("../resources/listOfStock.txt");
	char filename[ ] = "../resources/fileOfStock.dat";

	if (n != 10) {
		ifs >> n;
	}
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', STK_MAX_BUF);
	RecordFile <Stock> stockFile (buffer);

	// Write test
	stockFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Stock m;
		ifs >> m;
		
		int recAddr;
		if ((recAddr = stockFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
		else { cout << "Write at " << recAddr << endl; }
	}
	stockFile.Close ();


	// Read Test
	stockFile.Open (filename, ios::in);
	for (int i = 0; i < n; i++) {
		Stock m;
		stockFile.Read(m);
		cout << m;
	}
	stockFile.Close();
};

#ifdef test_stockTest
int main() {
	stockTest();

	return 0;
}
#endif

#endif
