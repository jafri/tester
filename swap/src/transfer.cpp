#include <swap/swap.hpp>

namespace proton {
  void swap::ontransfer (const name& from, const name& to, const asset& quantity, const string& memo) {
    // Skip if outgoing
    if (from == get_self()) {
      return;
    }

    // Skip if deposit from system accounts
    if (from == "eosio.stake"_n || from == "eosio.ram"_n || from == "eosio"_n) {
      return;
    }

    // Auth
    require_auth(from);

    // Process memo
    const auto token_contract = get_first_receiver();
    // process_memo(from, quantity, memo);
  }

//   void swap::process_memo (name from, asset quantity, string& memo) {
//     if (memo.empty())
//     {
//       append_token(from, token);
//     }
//     else
//     {
//       vector<string> vec_result;
//       char delimiter = ',';
//       split(memo, delimiter, vec_result);
//       string errMemo = "Wrong memo format. You are sending memo '" + memo + "' but must be empty memo or '{share symbol},{minimum expected amount}'";
//       check(!(vec_result.size() != 2), errMemo);

//       auto lt_symbol = symbol_code(vec_result[0]);
//       auto min_expected_amount = atoll(vec_result[1].c_str());

//       check(!(min_expected_amount <= 0), "minimum expected amount must be bigger then 0");

//       auto itr = pools_.require_find(lt_symbol.raw(),
//         string("lt_symbol does not exist in pools table: " + vec_result[0]).c_str());

//       token = subtruct_fee_for_protocol(token, exchange_fee_for_protocol_id);

//       token_ex send_exchange_token;

//       if (itr->pool1.quantity.symbol.code() == token.quantity.symbol.code()
//         && itr->pool1.assettype == token.assettype)
//       {
//         auto token_to_transfer_amount_pool2 = compute_transfer(itr->pool1, itr->pool2, token.quantity, itr->fee.exchange_fee);

//         send_exchange_token = itr->pool2;
//         send_exchange_token.quantity.amount = token_to_transfer_amount_pool2;

//         check(!(token.quantity.symbol.precision() != itr->pool1.quantity.symbol.precision()),
//           " token has wrong precision = " + to_string(token.quantity.symbol.precision())
//           + " but must be " + to_string(itr->pool1.quantity.symbol.precision()));

//         pools_.modify(itr, get_self(), [&](auto& s) {
//           s.pool1.quantity.amount += token.quantity.amount;
//           s.pool2.quantity.amount -= token_to_transfer_amount_pool2;
//         });

//         check(!(token_to_transfer_amount_pool2 < min_expected_amount),
//           "You set min_expected_amount" + to_string(min_expected_amount) + " but after exchange amount will be " + to_string(token_to_transfer_amount_pool2));
//       }
//       else if (itr->pool2.quantity.symbol.code() == token.quantity.symbol.code()
//         && itr->pool2.assettype == token.assettype)
//       {
//         auto token_to_transfer_amount_pool1 = compute_transfer(itr->pool2, itr->pool1, token.quantity, itr->fee.exchange_fee);

//         send_exchange_token = itr->pool1;
//         send_exchange_token.quantity.amount = token_to_transfer_amount_pool1;

//         check(!(token.quantity.symbol.precision() != itr->pool2.quantity.symbol.precision()),
//           " token has wrong precision = " + to_string(token.quantity.symbol.precision())
//           + " but must be " + to_string(itr->pool2.quantity.symbol.precision()));

//         pools_.modify(itr, get_self(), [&](auto& s) {
//           s.pool1.quantity.amount -= token_to_transfer_amount_pool1;
//           s.pool2.quantity.amount += token.quantity.amount;
//         });

//         check(!(token_to_transfer_amount_pool1 < min_expected_amount),
//           "You set min_expected_amount" + to_string(min_expected_amount) + " but after exchange amount will be " + to_string(token_to_transfer_amount_pool1));
//       }
//       else
//       {
//         check(false, "Wrong symbol for " + token.quantity.symbol.code().to_string());
//       }
//       send_tokens(get_self(), vector<token_ex>{send_exchange_token}, from, memo);
//     }
//   }
}