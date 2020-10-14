#pragma once

// Standard.
#include <optional>
#include <vector>

// EOS
#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/crypto.hpp>
#include <eosio/transaction.hpp>

// Local
#include "constants.hpp"
#include "tables.hpp"

using namespace eosio;
using namespace std;

namespace proton {
  class [[eosio::contract("swap")]] swap : public contract {
  public:
    using contract::contract;

    swap(name receiver, name code, datastream<const char*> ds)
      : contract(receiver, code, ds) {}

    // This functions will be called when the contract is notified of
    // incoming or outgoing transfer actions from any token contract
    [[eosio::on_notify("*::transfer")]]
    void ontransfer( const name& from,
                     const name& to,
                     const asset& quantity,
                     const string& memo       );


  // Private functions (not in ABI)
  private:
  	// deposits deposits_;
    // accounts accounts_;
    // stats stats_;
    // pools pools_;
    // conf config_;
    // proposals proposals_;

    // globall cstate_;
  };
}