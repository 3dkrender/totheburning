#include <eosio/eosio.hpp>
// ***** IMPORTANT *****
#include <eosio/singleton.hpp>
// *********************

using namespace eosio;
using namespace std;

CONTRACT totheburning : public contract
{
public:
   using contract::contract;

   [[eosio::on_notify("atomicassets::transfer")]] void
   gettransfer(
       name from,
       name to,
       vector<uint64_t> asset_ids,
       string memo);

private:
    TABLE burned
    {
        uint64_t burned_items = 0;
    } burned_reg;
    typedef singleton<"burned"_n, burned> t_burned;

    t_burned _burned = t_burned(get_self(), get_self().value);
};