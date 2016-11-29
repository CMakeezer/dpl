#ifndef DPLP_ANYPROMISE_INCLUDED
#define DPLP_ANYPROMISE_INCLUDED

//@PURPOSE: Provide a concept that is satisfied by promise types.
//
//@CONCEPTS:
//  dplp::AnyPromise: concept satisified by promises
//
//@SEE ALSO: dplp_promise
//
//@AUTHOR: David Sankel (dsankel@bloomberg.net)
//
//@DESCRIPTION: This component provides a concept that is satisfied by any
// 'dplp::Promise' type. This is intended to be used to help aid SFINE when the
// "promisness" of a type needs to be queried on the result of a metafunction.
//
// Note that this component depends "in name only" on dplp_promise.
//
///Usage
///-----
// This section illustrates intended use of this component.
//
///Example 1: Overload when the nested type is a promise
///- - - - - - - - - - - - - - - - - - - - - - - - - - -
// Suppose that we want to write a function that takes in a container and has a
// special overload when the container has promise elements. We presume the
// existence of a conforming `Container` concept from the Ranges TS.
//
// First, we declare the signature for the non-tuple overload:
//..
//  template<Container C>
//  requires !dplp::AnyPromise<typename C::value_type>
//  int f(C c);
//..
// Finally, we declare the signature for the tuple overload:
//..
//  template<Container C>
//  requires dplp::AnyPromise<typename C::value_type>
//  int f(C c);
//..

namespace dplp {
template <typename... Types> class Promise;

template <typename T>
concept bool AnyPromise = requires(T t){{t}->Promise<auto...>};
// This concept is satisified by `dplp::Promise` template instantiations.
}

#endif
