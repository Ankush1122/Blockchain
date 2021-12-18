#include "include/BlockChain.h"
#include "include/Transaction.h"

std::string epoch_to_utc(std::string epoch)
{
	long temp = stol(epoch);
	const time_t old = (time_t)temp;
	struct tm *oldt = gmtime(&old);
	return asctime(oldt);
}

int main()
{
	BlockChain chain;

	/*std::time_t time1;
	Transaction tr1(100, 1, 2, time(&time1));
	std::time_t time2;
	Transaction tr2(100, 1, 2, time(&time2));

	std::vector<Transaction> trVec1 = {tr1, tr2};
	chain.mineBlock(trVec1);

	std::time_t time3;
	Transaction tr3(100, 1, 2, time(&time3));

	std::vector<Transaction> trVec2 = {tr3};
	chain.mineBlock(trVec2);

	chain.printBlockChain();

	std::string temp = std::to_string(tr1.getTimeStamp());
	std::cout << "time : " << epoch_to_utc(temp);
	*/

	return 0;
}
