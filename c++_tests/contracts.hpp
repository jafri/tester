#pragma once
#include <eosio/testing/tester.hpp>

namespace eosio { namespace testing {

struct contracts {
   static std::vector<uint8_t> system_wasm() { return read_wasm("/Users/jafri/proton-boilerplate/tests/system_wasms/eosio.system.wasm"); }
   static std::vector<char>    system_abi() { return read_abi("/Users/jafri/proton-boilerplate/tests/system_wasms/eosio.system.abi"); }
   static std::vector<uint8_t> token_wasm() { return read_wasm("/Users/jafri/proton-boilerplate/tests/system_wasms/eosio.token.wasm"); }
   static std::vector<char>    token_abi() { return read_abi("/Users/jafri/proton-boilerplate/tests/system_wasms/eosio.token.abi"); }

   static std::vector<uint8_t> swap_wasm() { return read_wasm("/Users/jafri/proton-boilerplate/tests/../swap/swap.wasm"); }
   static std::vector<char>    swap_abi() { return read_abi("/Users/jafri/proton-boilerplate/tests/../swap/swap.abi"); }

   struct util {

   };
};
}} //ns eosio::testing
