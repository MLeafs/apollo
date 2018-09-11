/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBERTRON_TOPOLOGY_MANAGER_NODE_MANAGER_H_
#define CYBERTRON_TOPOLOGY_MANAGER_NODE_MANAGER_H_

#include <memory>
#include <string>
#include <vector>

#include "cybertron/topology/container/single_value_warehouse.h"
#include "cybertron/topology/manager/manager.h"
#include "cybertron/topology/role/role.h"

namespace apollo {
namespace cybertron {
namespace topology {

class Topology;

class NodeManager : public Manager {
  friend class Topology;

 public:
  using RoleAttrVec = std::vector<RoleAttributes>;
  using NodeWarehouse = SingleValueWarehouse;

  NodeManager();
  virtual ~NodeManager();

  bool HasNode(const std::string& node_name);
  void GetNodes(RoleAttrVec* nodes);

 private:
  bool Check(const RoleAttributes& attr) override;
  void Dispose(const ChangeMsg& msg) override;
  void OnTopoModuleLeave(const std::string& host_name, int process_id) override;

  void DisposeJoin(const ChangeMsg& msg);
  void DisposeLeave(const ChangeMsg& msg);

  NodeWarehouse nodes_;
};

}  // namespace topology
}  // namespace cybertron
}  // namespace apollo

#endif  //  CYBERTRON_TOPOLOGY_MANAGER_NODE_MANAGER_H_
