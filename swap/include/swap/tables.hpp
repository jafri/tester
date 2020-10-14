#pragma once

#include <eosio/eosio.hpp>
#include <eosio/singleton.hpp>

using namespace eosio;
using namespace std;

namespace proton {
  /**
   * GLOBAL
   */
  struct [[eosio::table, eosio::contract("swap")]] globall {
		globall() {}
		uint16_t exchange_fee_for_protocol         = 0;
		uint16_t add_liquidity_fee_for_protocol    = 0;
		uint16_t remove_liquidity_fee_for_protocol = 0;
		uint16_t last_proposal_id                  = 0;
		uint16_t exchange_fee_default              = 0;
		uint16_t add_liquidity_fee_default         = 0;
		uint16_t remove_liquidity_fee_default      = 0;
		uint64_t spare1                            = 0;
		uint64_t spare2                            = 0;
		uint64_t spare3                            = 0;
		uint64_t spare4                            = 0;
		uint64_t spare5                            = 0;
		uint64_t spare6                            = 0;
	};

  /**
   * POOLS
   */
	struct pool_base {
		symbol	lt_symbol;
		name	  creator;
		string		memo;
		asset	pool1;
		asset	pool2;
		uint128_t	    hash;
		pool_fee	    fee;

		void set_pool1(asset new_pool1)
		{
			check(!(new_pool1.amount <= 0), " pool1 must be positive value");
			pool1 = new_pool1;
		}

		void set_pool2(asset new_pool2)
		{
			check(!(new_pool2.amount <= 0), " pool2 must be positive value");
			pool2 = new_pool2;
		}

		void set_memo(const string& new_memo)
		{
			check(!(new_memo.size() > MEMO_MAX),
				"Memo size is " + to_string(new_memo.size()) + " which is bigger then maximum allowed " + to_string(MEMO_MAX));
			memo = new_memo;
		}
	};

	// Proposal
  struct [[eosio::table, eosio::contract("swap")]] proposal: public pool_base {
		uint64_t id;

    uint64_t primary_key()const { return id; }

    uint128_t by_hash() const {
      return hash;
    }
	};

	// Pool
  struct [[eosio::table, eosio::contract("swap")]] pool: public pool_base {
		uint16_t	reserved;

		uint64_t primary_key()const { return lt_symbol.code().raw(); }

		uint128_t by_hash() const {
			return hash;
		}
	};

  /**
   * Create tables
   */
	typedef multi_index< "proposals"_n, proposal,
		indexed_by<"hash"_n, const_mem_fun<proposal, uint128_t, &proposal::by_hash>>
	> proposals;
	typedef multi_index< "pools"_n, pool,
		indexed_by<"hash"_n, const_mem_fun<pool, uint128_t, &pool::by_hash>>
	> pools;
	typedef singleton< "globall"_n, globall> conf;
}