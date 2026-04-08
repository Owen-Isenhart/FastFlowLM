/// \file embedding_model.hpp
/// \brief embedding_model class
/// \author FastFlowLM Team
/// \date 2025-06-24
/// \version 0.9.10
/// \note This class is a virtual class for embedding models
/// \note All other embedding models should inherit from this class so that they can be used in the same way.
/// \warning ABI-BREAKING CHANGE: The embed() signature has been updated for const-correctness (std::vector<int>& to const std::vector<int>&).
///          All dependent shared libraries (e.g., gemma_embedding, etc.) must be rebuilt
///          as vtable layout changes will cause runtime failures with prebuilt binaries.
#pragma once
#include "tensor_utils/q4_npu_eXpress.hpp"
#include "tensor_2d.hpp"
#include "utils/utils.hpp"
#include "buffer.hpp"



/// \brief causal_lm class
class embedding_model {
public:
    embedding_model(){}
    virtual ~embedding_model(){}

    /// \brief load the weights
    /// \param q4nx the q4nx
    virtual void load_weights(Q4NX& q4nx) = 0;
    /// \brief embed the embedding_model
    /// \param x the input
    /// \return the output
    virtual buffer<bf16> embed(const std::vector<int>& tokens) = 0;
};