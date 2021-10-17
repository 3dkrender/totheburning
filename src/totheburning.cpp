#include <totheburning.hpp>

[[eosio::on_notify("atomicassets::transfer")]] void
totheburning::gettransfer(
    name from,
    name to,
    vector<uint64_t> asset_ids,
    string memo)
{
    // Check for legitimate transfer
    check(from != _self && to == _self, "Wrong data!");

    // Burn Em' All!
    for (auto it = asset_ids.begin(); it != asset_ids.end(); it++)
    {
        action(
            permission_level{get_self(), name("active")},
            name("atomicassets"),
            name("burnasset"),
            make_tuple(get_self(), *it))
            .send();
    }

    // Update (and create if needed) singleton table
    auto burned = _burned.get_or_create(_self, burned_reg);
    burned.burned_items += asset_ids.size();
    _burned.set(burned, _self);
}
