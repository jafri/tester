#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

namespace proton
{
  static constexpr double FEE_PRECISION = 100;
  static constexpr double FEE_PERCENT = 5;
  static constexpr double FEE_MAX = FEE_PERCENT * FEE_PRECISION;
  static constexpr uint16_t MEMO_MAX = 1024;
  static constexpr uint16_t FT_TOKENS_MAX = 100;
  const int64_t MAX_SUPPLY = eosio::asset::max_amount;

  static constexpr eosio::name SIMPLEASSETS_CONTRACT = "simpleassets"_n; // SimpleAssets CONTRACT
  static constexpr eosio::name PROTOCOL_FEE_CONTRACT = "protocolfee1"_n; // Protocol fee contract CONTRACT;

  enum operation_type {
    append   = 0,
    subtruct = 1
  };
  enum fee_type {
    exchange_fee_for_protocol_id         = 0,
    add_liquidity_fee_for_protocol_id    = 1,
    remove_liquidity_fee_for_protocol_id = 2,
    exchange_default_id                  = 3,
    add_liquidity_default_id             = 4,
    remove_liquidity_default_id          = 5
  };

  struct pool_fee
  {
    uint16_t	exchange_fee;
    uint16_t	add_liquidity_fee;
    uint16_t	remove_liquidity_fee;
  };

} // namespace proton